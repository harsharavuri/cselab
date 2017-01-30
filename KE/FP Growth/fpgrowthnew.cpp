#include<bits/stdc++.h>
using namespace std;
struct fpt{
	int data;
	int freq;
	int count=0;
	fpt* children[20];
	fpt* parent;
};
const int candidates=5;
const int minsup=2;

struct nodelink{
	nodelink* next;
	int data;
	fpt* store;
};



void print(fpt* t){
	if(t==NULL)return;
	if(t->parent!=NULL)cout<<t->data<<"  "<<t->freq<<" -- ";
	for(int i=0;i<t->count;i++)print(t->children[i]);
	cout<<endl;
}


fpt* insert(fpt* fp, int finalList[],int count, int i,nodelink* nl[],int freqList[]=NULL){
	
	int j=0;
	for(int k=0;k<fp->count;k++){
		if(fp->children[k]->data==finalList[count]){
			fp->children[k]->freq++;
			if(count+1!=i){
				fp->children[k]=insert(fp->children[k],finalList,count+1,i,nl,freqList);
			}
			return fp;
		}
	}
	//cout<<"yo ";
	fp->children[fp->count]=new fpt();
	fp->children[fp->count]->data=finalList[count];
	fp->children[fp->count]->freq=1;
	if(freqList!=NULL)fp->children[fp->count]->freq=freqList[count];
	fp->children[fp->count]->parent=fp;
	
	if(nl[finalList[count]]==NULL){
		nl[finalList[count]]= new nodelink();
		nl[finalList[count]]->data=finalList[count];
		nl[finalList[count]]->store=new fpt();
		nl[finalList[count]]->next=NULL;
		nl[finalList[count]]->store=fp->children[fp->count];
	}else{
		nodelink* temp=new nodelink();temp=nl[finalList[count]];
		while(temp->next!=NULL)temp=temp->next;
		
			temp->next = new nodelink();
			temp=temp->next;
			temp->store=new fpt();
			temp->store=fp->children[fp->count];
			temp->next=NULL;
			temp->data=finalList[count];
		
	}
	
	
	for(int y=0;y<20;y++)fp->children[fp->count]->children[y]=NULL;
	if(count+1!=i)insert(fp->children[fp->count],finalList, count+1,i,nl);
	fp->count++;
	//print(fp);
	return fp;
}


void swap(int* a, int* b){
	int temp = *a;*a=*b;*b=temp;
}


void getFP(int cand[], int sortedcand[]){
	ifstream ifs("invert.txt");
	char s[100];
	int j=0;
	while(ifs.getline(s,100,'\n')){
		char ch;//cout<<s<<"s"<<endl;
		int i=0;
		while(s[i]!='\0'){
			if(s[i]==' ' || s[i]=='\t' || s[i]=='\n')cand[j]++;
			i++;
		}
		j++;
	}
	// Initialise the candidates
	
	for(int i=0;i<candidates;i++)sortedcand[i]=i;
	
	// Sorting
	for(int i=0;i<candidates-1;i++){
		for(int j=i+1;j<candidates;j++){
			if(cand[i]<cand[j]){
				swap(&cand[i],&cand[j]);
				swap(&sortedcand[i], &sortedcand[j]);
			}
		}
	}
	ifs.close();
	
}

int getSortedList(int sortedcand[], char ch[], int finalList[]){
	int a[candidates];int k=0;
	int i=0;char temp[20];
	while(ch[i]!=' ')i++;
	while(ch[i]==' ')i++;
	i++;
	while(ch[i]!='\0'){
		int j=0;
		while(ch[i]!=' ' && ch[i]!='\0'){
			temp[j++]=ch[i++];
		}
		temp[j]='\0';
		a[k++]=atoi(temp);
		if(ch[i]!='\0'){
			while(ch[i]==' ')i++;
			i++;
		}
	}
	
	//int finalList[candidates];
	int y=0;int l=0;
	for(int y=0;y<candidates;y++){
		for(int z=0;z<k;z++){
			if(sortedcand[y]==a[z])finalList[l++]=a[z];
		}
	}
	return l;
	
	
}

void printParent(fpt* fp){
	while(fp->parent!=NULL){
		cout<<fp->data<<"  ";//<<fp->freq<<"  --  ";
		fp=fp->parent;
	}
	return;
}

void printnl(nodelink* temp){
	while(temp!=NULL){
		printParent(temp->store);
		temp=temp->next;
		cout<<endl;
	}
}


void remove(fpt* t){
	if(t==NULL)return;
	for(int i=0;i<t->count;i++){
		if(t->children[i]->freq<minsup){
			
			for(int j=i;j<t->count-1;j++){
				t->children[j]=t->children[j+1];
			}
		}
	}
}


void FPGrowthMining(fpt* m, int sortedcand[], nodelink* nl[]){
	if(m==NULL)return;
	for(int i=0;i<candidates;i++){
		fpt* local=new fpt();
			local->data=-1;
			local->freq=-1;
			local->parent=NULL;
			for(int i=0;i<20;i++)local->children[i]=NULL;
			nodelink* nlNew[5];
			for(int i=0;i<candidates;i++)nlNew[i]=NULL;
			//cout<<"yo ";
			if(nl[i]!=NULL){
				nodelink* temp=new nodelink();temp=nl[i];
				if(temp->store->parent==NULL)continue;
				//temp=temp->next;
				while(temp->next!=NULL){
					int l=0;int finalList[5];int freqList[5];
					fpt* t = new fpt();
					t=temp->store->parent;
					while(t->parent!=NULL){
						finalList[l]=t->data;
						freqList[l]=t->freq;
						l++;t=t->parent;
					}
					local = insert(local, finalList, 0, l,nlNew, freqList);		
					//cout<<"yo ";
					temp=temp->next;
				}
			}
			
			remove(local);
		
		/*	for(int y=0;y<5;y++){
				if(nlNew[y]!=NULL){
					
					nodelink* temp=new nodelink();
					temp=nlNew[y];
					if(nlNew[y]->store->freq<minsup){
						//cout<<"yo ";
						//cout<<nlNew[y]->store->freq;
						//cout<<"yo 2";
						while(nlNew[y]!=NULL && nlNew[y]->store->freq<minsup){
							nlNew[y]->store=NULL;
							//cout<<"yo ";
							if(temp->next->next!=NULL)nlNew[y]=temp->next->next;
							else nlNew[y]=NULL;
						}
					}
					cout<<"yo ";
					while(temp!=NULL && temp->next!=NULL){
						cout<<"yo ";
						if(temp->next->store->freq<minsup){
							//cout<<"yo  "<<temp->next->store->data<<" "<<temp->next->store->freq<<" yo ";
							temp->next->store=NULL;
							if(temp->next->next!=NULL){
								temp->next=temp->next->next;
							}else{
								temp->next=NULL;
							}
						}
						cout<<"yo ";
						temp=temp->next;
					}
	
				}
		 }*/
			
			
			cout<<i<<" ------ ";print(local);
			//print(local);
			cout<<endl<<endl;
	}
}



int main(){
	int sortedcand[candidates];
	int cand[candidates]={0};
	
	
	getFP(cand, sortedcand);
	
	nodelink* nl[candidates];
	
	for(int i=0;i<5;i++){
		nl[i]=NULL;
	}
	
	fpt* m=new fpt();
	m->data=-1;
	m->freq=-1;
	m->parent=NULL;
	for(int i=0;i<20;i++)m->children[i]=NULL;
	char ch[100];
	ifstream ifs("trans.txt");
	//for(int i=0;i<5;i++)cout<<sortedcand[i]<<" ";
	while(ifs.getline(ch,100)){
		int i=0,count=0;;
		int finalList[candidates];
		i=getSortedList(sortedcand, ch, finalList);
		m=insert(m,finalList,count, i,nl);
	}

	//print(m);
	FPGrowthMining(m, sortedcand,nl);
	
}

