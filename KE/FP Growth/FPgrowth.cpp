#include<bits/stdc++.h>
using namespace std;
const int minsup=5;
const int candidates=5;
const int trans=10;

struct node{
	char val[10];
	int freq;
};

struct fptree{
	node data;
	fptree* nextsibling;
	fptree* child;	
};

void print(fptree* fp){
	if(fp==NULL)return;
	cout<<fp->data.val<<"  "<<fp->data.freq<<"  ";
	fptree* temp=fp;
	while(temp->nextsibling != NULL){
		//cout<<"haa ";
		print(temp->nextsibling);
		temp = temp->nextsibling;
	}
	cout<<endl;
	print(fp->child);
}

fptree* insert(fptree* fp, char ch[]){
	//cout<<ch<<" yo ";
	if(ch[0]=='\0')return NULL;
	char *check=ch;
	fptree* fptemp=new fptree();
	fptemp = fp;
	char buff[10];
		int i=1;buff[0]='I';ch++;
		while(*ch!='\0' && *ch!='I'){
			buff[i]=*ch;
			ch++;i++;
		}
		buff[i]='\0';
		//ch++;
		//cout<<"yo ";
	if(fp==NULL){
		//cout<<"yo ";
		fp = new fptree();
		fp->nextsibling=NULL;fp->child=NULL;
		strcpy(fp->data.val, buff);
		fp->data.freq=1;
		//ch++;
		return fp;
	}else{
		//cout<<buff<<endl;
		if(!strcmp(buff,fp->data.val)){
			fp->data.freq++;
			//cout<<"yo";
				
			fp->child = insert(fp->child, ch);
			return fp;
		}
		//fptree* temp=new fptree();temp=fp;
		while(fp->nextsibling!=NULL){
			//cout<<"yo";
			if(!strcmp(buff,fp->data.val)){
				fp->data.freq++;
				fp->child = insert(fp->child, ch);
				return fptemp;
			}
			fp = fp->nextsibling;	
		}
		//fp->nextsibling = new fptree();
		fp->nextsibling = insert(fp->nextsibling,check);
		return fptemp;
	}
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



fptree* secondDBScan(int sortedcand[], fptree* fp){
	ifstream ifs("trans.txt");
	string s;
	int j=0;
	while(!ifs.eof()){
		getline(ifs,s);
		//cout<<s<<endl;
		int check[candidates]={0};
		char buff[10];//cout<<s<<"s"<<endl;
		int i=0;
		while(s[i]!='\0' && s[i]!=' ')i++;
		
		while(s[i]!='\0'){
			int j=0;
			while(s[i]!='I')i++;
			i++;
			while(s[i]!=' ' && s[i]!='\0'){
				buff[j]=s[i];j++;i++;
			}
			buff[j]='\0';
			
			int v = atoi(buff);
			//cout<<v<<"   ";
			for(int y=0;y<candidates;y++){
				if(sortedcand[y]==v){
					check[y]=-1;break;
				}
			}
		}
		
		char ch[100]="";
		
		for(int y=0;y<candidates;y++){
			if(check[y]==-1){
				strcat(ch,"I");
				char buff[10];
				strcat(ch,itoa(sortedcand[y],buff,10));
			}
		}
		//cout<<ch<<" s ";
		if(strcmp(ch,"")){
			//cout<<ch<<" s ";
			fp = insert(fp, ch);
			//cout<<s<<endl;
			//print(fp);//cout<<fp->data.val<<"   ";
		}
		//cout<<ifs.eof()<<"yo";
	}
	//print(fp);
	return fp;
}


int main(){
	int sortedcand[candidates];
	int cand[candidates]={0};
	int check[candidates]={0};
	getFP(cand, sortedcand);
	for(int i=0;i<candidates;i++){
		if(cand[i]<minsup){
			//sortedcand[i]=-1;cand[i]=-1;
		}
		//cout<<cand[i]<<"  "<<sortedcand[i]<<endl<<endl;
	}
	
	fptree* fp = NULL;
	fp = secondDBScan(sortedcand, fp);
	print(fp);
}
