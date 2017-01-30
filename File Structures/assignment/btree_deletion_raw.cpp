// Sri Harsha Aditya
// Roll no:147241

#include<iostream>
using namespace std;
const int size = 4;
typedef struct bnode{
	int count=0;
	int data[size];
	bnode* next[size+1];
	bnode* pptr;
	node_cons(){
		for(int i=0;i<size;i++){
			data[i]=0;
			//count=0;
			next[i]=NULL;
		}
		next[size]=NULL;
	}
}*bnd;
void deletenode(bnd &T,int d);
int isdelkeyred_leaf(bnd &T);
int isdelkeyred_internal(bnd &T);
int data;
void delkeyred_internal(bnd &T,int y,int d);
bnd tt=NULL;
bnd root=NULL;
void sort(int a[],int size){
	for(int i=0;i<size;i++){
		int min=a[i];
		for(int j=i;j<size;j++){
			if(a[j]<min){
				int temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
}
int check_key_red(bnd &T){
	if(T->pptr==NULL)return -1;
	else{
		for(int i=0;i<=size&&T->pptr->next[i]!=NULL;i++){
			if(T->pptr->next[i]!=NULL){
				for(int j=0;j<size;j++)
				if(T->pptr->next[i]->data[j]==0)
				return i;
			}
		}
	}
	return -1;
}
int find_ptr(bnd &T){
	bnd temp=new(bnode);
	temp=T->pptr;
		for(int i=0;i<=size;i++){
		//cout<<temp->data[0]<<"  ";
		if(temp->next[i]->data[0]==T->data[0])
		return i;
	}
}
int key_red(bnd &T,int i,int j){
	int store;
	int a[size];
	
	if(i<j){
		store=T->next[i]->data[size-1];
		for(int k=0;k<size-1;k++)a[k]=T->next[i]->data[k];
		a[size-1]=data;
		for(int m=0;m<size;m++){
				int min=a[m];
				for(int n=m;n<size;n++){
					if(min>a[n]){
						int temp=a[n];
						a[n]=a[m];
						a[m]=temp;
					}
				}
			}
		
		for(int k=j;k>i;k--){
			if(k==j){
				int y;
				for(y=0;y<size&&T->next[k]->data[y]!=0;y++);y--;
				for(int l=y;l>=0;l--)T->next[k]->data[l+1]=T->next[k]->data[l];
				T->next[k]->data[0]=T->data[k-1];
			}
			else{
				T->data[k]=T->next[k]->data[size-1];
				for(int l=size-2;l>=0;l--)T->next[k]->data[l+1]=T->next[k]->data[l];
				T->next[k]->data[0]=T->data[k-1];
			}
			
		}
		T->data[i]=store;
		for(int k=0;k<size;k++)T->next[i]->data[k]=a[k];
	}else{
		for(int k=j;k<i;k++){
			if(k==j){
				int y;
				for(y=0;y<size&&T->next[k]->data[y]!=0;y++);
				//for(int l=y;l>0;l--)T->next[k]->data[l+1]=T->next[k]->data[l];
				T->next[k]->data[y]=T->data[k];
			}
			else{
				T->data[k-1]=T->next[k]->data[0];
				for(int l=0;l<size-1;l++)T->next[k]->data[l]=T->next[k]->data[l+1];
				T->next[k]->data[size-1]=T->data[k];
			}
		
		}		
			for(int k=1;k<=size-1;k++)a[k]=T->next[i]->data[k];
			a[0]=data;
			sort(a,size);
			for(int m=0;m<size;m++){
				int min=a[m];
				for(int n=m;n<size;n++){
					if(min>a[n]){
						int temp=a[n];
						a[n]=a[m];
						a[m]=temp;
					}
				}
			}
			//cout<<a[0]<<a[1]<<a[2]<<a[3]<<"   ";
			T->data[i-1]=T->next[i]->data[0];
			for(int k=0;k<size;k++)T->next[i]->data[k]=a[k];
	}
}

void sort_node(bnd ab[],int size){
	int i=0;
	int j=0;
	for(int j=0;j<=size+1&&ab[j]!=NULL;j++);
	//if(data==6&&ab[0]!=NULL)cout<<j;
	for(int i=0;i<j;i++){
		bnd min=new(bnode);min=ab[i];
		for(int k=i;k<j;k++){
			if(ab[k]->data[0]<min->data[0]){
				bnd temp=new(bnode);
				temp=ab[k];
				ab[k]=ab[i];
				ab[i]=temp;
			}
		}
	}
}
bnd node_splitting(bnd &T){
	//if(data==15)cout<<T->next[0]<<"  ";
	bnd temp=new(bnode);int k=0;
	temp->node_cons();
	int a[size+1];
	for(int i=0;i<size;i++){
		a[i]=T->data[i];
	}

	a[size]=data;
	sort(a,size+1);
	for(int i=0;i<size/2;i++)T->data[i]=a[i];
	//if(T->next[0]==NULL){
	//	temp->data[k]=a[size/2];k++;
	//}
	for(int i=size/2+1;i<=size;i++){
			
		temp->data[k]=a[i];k++;
		T->data[i-1]=0;
		//if(data==15)cout<<T->next[0]<<"  ";
	}
			//if(data==15)cout<<T->next[0]<<"  ";
	//T->data[size/2]=0;
	data=a[size/2];
	bnd ab[size+2];
	//if(data==15)
	//cout<<data<<" ";
	//if(data==15)cout<<T->next[0]<<"  ";
	if(T->next[0]!=NULL){
		//cout<<"  a  ";
		for(int i=0;i<=size;i++)
		{
			ab[i]=new(bnode);
			ab[i]=T->next[i];
		}
		ab[size+1]=NULL;
		if(tt!=NULL){
		tt->pptr=temp;
		ab[size+1]=tt;
		
		}
	
		sort_node(ab,size);
		for(int i=0;i<=size/2;i++){
			//if(data==6)cout<<T->next[size/2]->data[0];
			T->next[i]=ab[i];
			if(T->next[i]!=NULL)T->next[i]->pptr=T;
		}
		//T->next[size/2]=NULL;
		T->next[size/2+1]=NULL;
		k=0;
		for(int i=size/2+1;i<size+1;i++){
			temp->next[k]=new(bnode);
			*temp->next[k] = *ab[i];
			temp->next[k]->pptr=NULL;
			if(temp->next[k]!=NULL){
				
			temp->next[k]->pptr=new(bnode);
			temp->next[k]->pptr=temp;
			}
			
			k++;
			//if(data==9)cout<<temp->next[0]->pptr->data[0]<<" ";	
			T->next[i]=NULL;	
		}
		
		temp->next[k]=ab[size+1];
		if(temp->next[k]!=NULL){
			bnode te;te=*ab[size+1];te.pptr=NULL;*temp->next[k]=te;
		temp->next[k]->pptr=new(bnode);
		temp->next[k]->pptr=temp;
	
		}
	}
	//if(data==15)cout<<T->data[0]<<temp->data[0]<<" bbb ";
	//T->data[size/2]=0;
	data=a[size/2];
	tt=NULL;
	return temp;
}
//bnd root;

int isleafnode(bnd T){
	if(T->next[0]==NULL)return 1;
	else
	return 0;
}
int len_node(bnd T){
	int l;
	for(l=0;l<size&&T->data[l]!=0;l++);
	return l;
}


int isdelkeyred_leaf(bnd &T){
	if(T->pptr==NULL)return 0;
	
	int p=find_ptr(T);
	
	bnd temp=new(bnode);
	temp=T->pptr;
	int l=len_node(temp);
	if(p<l)
	if(len_node(temp->next[p+1])>size/2)
	return 1;
	if(p>0)
	if(len_node(temp->next[p-1])>size/2)return 2;
	return 0;
}
void delkeyred_leaf(bnd &T,int y,int d){
	bnd temp=new(bnode);
	int p=find_ptr(T);
	int len=len_node(T);
	//len;
	if(y==1){		// 1 for right and 2 for left
	
	temp=T->pptr->next[p+1];
	T->data[len]=T->pptr->data[p];
	T->pptr->data[p]=temp->data[0];
	deletenode(temp,temp->data[0]);
	sort(T->data,len+1);
	deletenode(T,d);
	}
	if(y==2){
		
	temp=T->pptr->next[p-1];
	T->data[len]=T->pptr->data[p-1];
	T->pptr->data[p-1]=temp->data[len_node(temp)-1];
	deletenode(temp,temp->data[len_node(temp)-1]);
	sort(T->data,len+1);
	deletenode(T,d);
	}
}

int isdelkeyred_internal(bnd &T){
	if(T->pptr==NULL)return 0;
	int p=find_ptr(T);
	//bnd temp=new(bnode);
	if(p<size)
	if(len_node(T->next[p+1])>size/2)
	return 1;
	if(p>0)
	if(len_node(T->next[p])>size/2)return 2;
	return 0;
}

void delkeyred_internal(bnd &T,int y, int d){
		bnd temp=new(bnode);
		int p;
		for(p=0;p<size&T->data[p]!=d;p++);
		//int len=len_node(T);
		if(y==1){
			T->data[p]=T->next[p+1]->data[0];
			deletenode(T->next[p+1],T->next[p+1]->data[0]);
		}
		else if(y==2){
			T->data[p]=T->next[p]->data[len_node(T->next[p]-1)];
			deletenode(T->next[p],T->next[p]->data[len_node(T->next[p]-1)]);
		}
		return;
}
/*
void mergedelete_leaf(bnd &T){
	bnd temp=new(bnode);
		int p;
		//for(p=0;p<size&T->data[p]!=d;p++);
		p=find_ptr(T);
		if(p<size){
		temp=T->pptr->next[p+1];
		int len=len_node(T);
		T->data[len]=T->pptr->data[p];
		int i;
		for(i=0;i<=size/2&&temp->data[i]!=0;i++)
		{
			T->data[++len]=temp->data[i];
			T->next[len]=new(bnode);
			T->next[len]=temp->next[i];
		}
		T->next[++len]=new(bnode);
		T->next[len]=temp->next[i];
		for(int i=p+1;i<size-1;i++){
			T->pptr->data[p]=T->pptr->data[p+1];
			T->pptr->next[p]=T->pptr->next[p+1];
		}
		T->pptr->next[size-1]=T->pptr->next[size];
		T->pptr->next[size]=NULL;
		T->data[size-1]=0;
		
		
		}else if(p>0){
		temp=T->pptr->next[p-1];
		int len=len_node(temp);
		temp->data[len]=T->pptr->data[p-1];
		int i;
		for(i=0;i<=size/2&&T->data[i]!=0;i++)
		{
			temp->data[++len]=T->data[i];
			temp->next[len]=new(bnode);
			temp->next[len]=T->next[i];
		}
		temp->next[++len]=new(bnode);
		temp->next[len]=temp->next[i];
		T->next[++len]=new(bnode);
		T->next[len]=temp->next[i];
		for(int i=p;i<size-1;i++){
			T->pptr->data[p]=T->pptr->data[p+1];
			T->pptr->next[p]=T->pptr->next[p+1];
		}
		T->pptr->next[size-1]=T->pptr->next[size];
		T->pptr->next[size]=NULL;
		T->data[size-1]=0;
		
		}
		return;
}
*/

void mergedelete_internal(bnd &T,int d){
	bnd temp=new(bnode);
		int go;
		for(go=0;go<size&&T->data[go]!=d;go++);
		for(int i=go;i<size-1;i++){
			T->data[i]=T->data[i+1];
		}
		T->data[size-1]=0;
		int p;
		//cout<<" a v ";
		//for(p=0;p<size&T->data[p]!=d;p++);
		
		p=find_ptr(T);
	
		if(p<size){
		temp=T->pptr->next[p+1];
		int len=len_node(T);
		T->data[len]=T->pptr->data[p];
		int i;
		for(i=0;i<size/2&&T->next[0]!=NULL&&temp->next[i]!=NULL;i++){
			T->next[len]=new(bnode);
			*T->next[len]=*temp->next[i];
			if(T->next[len]!=NULL)T->next[len]->pptr=T;
		}
		
		for(i=0;i<size/2&&temp->data[i]!=0;i++)
		{	
			T->data[++len]=temp->data[i];
			
		}
		
		//if(T->next[0]!=NULL){
		//T->next[++len]=new(bnode);
		//*T->next[len]=*temp->next[i];
		//if(T->next[len]!=NULL)T->next[len]->pptr=T;}
		for(int i=p;i<size-1;i++){
			T->pptr->data[i]=T->pptr->data[i+1];
			T->pptr->next[i+1]=T->pptr->next[i+2];
		}
		//T->pptr->next[size-1]=T->pptr->next[size];
		T->pptr->next[size]=NULL;
		T->pptr->data[size-1]=0;
			
		}else if(p>0){
		
		temp=T->pptr->next[p-1];
		int len=len_node(temp);
		temp->data[len]=T->pptr->data[p-1];
		int i;
		for(i=0;i<=size/2&&T->data[i]!=0;i++)
		{
			temp->data[++len]=T->data[i];
			if(temp->next[0]!=NULL){
			temp->next[len]=new(bnode);
			*temp->next[len]=*T->next[i];
			if(temp->next[len]!=NULL)temp->next[len]->pptr=temp;}
		}
		if(temp->next[0]!=NULL){
		temp->next[++len]=new(bnode);
		*temp->next[len]=*T->next[i];
		if(temp->next[len]!=NULL)temp->next[len]->pptr=temp;}
		//T->next[++len]=new(bnode);
		//T->next[len]=temp->next[i];
		for(int i=p;i<size-1;i++){
			T->pptr->data[i]=T->pptr->data[i+1];
			T->pptr->next[i+1]=T->pptr->next[i+2];
		}
		//T->pptr->next[size-1]=T->pptr->next[size];
		T->pptr->next[size]=NULL;
		T->pptr->data[size-1]=0;
		
		}
		
		//if(T->pptr->data[0]==)
		return;
	
}
void mergedelete_internal_utility(bnd& T,int d){
			
			if(T->pptr==root){
			
			mergedelete_internal(T,d);
			if(T->pptr->data[0]==0){
			T->pptr=NULL;
			root=T;
			
			}
			//cout<<T->data[0];
			}
			else if(len_node(T->pptr)>size/2)
			{
				mergedelete_internal(T,d);
			}
			else{
				//cout<<T->data[0];
				int po=find_ptr(T);
				int l;
				if(po<size)
				l=T->pptr->data[po];
				else if(po>0)l=T->pptr->data[po-1];
				mergedelete_internal(T,d);
				
				mergedelete_internal_utility(T->pptr,l);
				
			}
}


bnd insert_and_sort(bnd &T,int size){
	//if(data>=6)return T;
	
	//if(data==7)cout<<"yeas";
	if(T==NULL){
		//cout<<"data"<<data<<"  ";
		T=new(bnode);
		T->node_cons();
		T->data[0]=data;
		T->pptr=NULL;
		tt->pptr=new(bnode);
		tt->pptr=T;
		//cout<<tt->data[0]<<" ";
		T->next[1]=new(bnode);
		T->next[1] = tt;
		T->next[1]->pptr=T;
		tt=NULL;
		root=T;
		return T;
	}else{
		int l;
		//cout<<data;
		for(l=0;l<size&&T->data[l]!=0;l++);
		int a[size+1];
		for(int i=0;i<l;i++){
			a[i]=T->data[i];
		}
		//if(l==size)a[size]=data;
		//if(data==7)
		//cout<<T->data[size-1];
		//return NULL;
		bnd ab[size+2];
		for(int i=0;i<size+2;i++){
			ab[i]=NULL;
		}
		for(int i=0;i<=l;i++){
			ab[i]=new(bnode);
			ab[i]=T->next[i];
			}
			//if(data==9)cout<<T->data[0]<<" "<<T->data[1]<<" "<<T->data[2]<<" "<<T->data[3]<<" ";
			//ab[l]=0;
			//ab[l+1]=0;
			ab[l+1]=NULL;
			if(tt!=NULL){
			ab[l+1]=new(bnode);
			tt->pptr=new(bnode);
			tt->pptr=T;
			ab[l+1]=tt;
			//cout<<ab[2]->data[0];
			tt=NULL;
			}
			sort_node(ab,size);
			if(l<size){
				for(int i=0;i<=l+1;i++)
				T->next[i]=ab[i];
				//if(data==8)cout<<"yeah";
				a[l]=data;
				sort(a,l+1);
				//if(data==6)
				//cout<<a[0];
				for(int i=0;i<=l;i++)T->data[i]=a[i];
				}else{
				/*int check=check_key_red(T);
				if(check!=-1){
					//cout<<"  a  ";
					int ptr = find_ptr(T);
					key_red(T->pptr,ptr,check);
					//cout<<ptr<<" "<<check<<" ";
					return T;
				}*/
				for(int i=0;i<=l;i++)T->next[i]=ab[i];
				tt=ab[size+1];bnd t1=new(bnode);
				int yl=0;
				t1=node_splitting(T);
				tt=new(bnode);
				tt=t1;int flag=0;
				//if(data==15)cout<<tt->data[0]<<" ";
				if(T->pptr==NULL)flag=1;
				
				T->pptr=insert_and_sort(T->pptr,size);
				//if(data==9)cout<<"  "<<T->data[0]<<"   ";
				if(flag){
				//if(data==6)cout<<"aa ";	
				if(T->pptr!=NULL){
					T->pptr->next[0]=new(bnode);
					T->pptr->next[0]=T;
					if(T->pptr->next[1]!=NULL)T->pptr->next[1]->pptr=T->pptr;
					//return T->pptr;
					}
				}//cout<<T->data[0]<<"  "<<T->pptr->data[0]<<"  "<<T->pptr->next[1]->data[0]<<"  ";
			}
		
		return T;
	}
}

bnd add(bnd &T)
{
if(T==NULL){
		T=new(bnode);
		T->node_cons();
		T->data[0]=data;
		
		T->count++;
		T->pptr=NULL;
		//cout<<T->data[0];
		return T;
	}
	if(data<T->data[0]&&T->next[0]!=NULL){
	
		T->next[0]=add(T->next[0]);
		if(T->next[0]!=NULL)T->next[0]->pptr=T;
		return T;
	}
	int yf=0;
	for(int i=0;i<size-1;i++){
		
		if(data>T->data[i]&&(data<T->data[i+1]||T->data[i+1]==0)&&T->next[i+1]!=NULL)
		{	//if(data==18)
			//{
			//cout<<"  enter "<<T->data[0];	
			//}
			T->next[i+1]=add(T->next[i+1]);
			if(T->next[i+1]!=NULL)T->next[i+1]->pptr=T;
			return T;
		}
		
	}
	
		
	if(data>T->data[size-1]&&T->next[size]!=NULL)
	{	//if(data==15)cout<<" a ";
	T->next[size]=add(T->next[size]);
	//if(T->next[size]!=NULL)T->next[size]->pptr=T->pptr;	
	return T;
	}
		
	T=insert_and_sort(T,size);
		
	//if(T->pptr!=NULL)return T->pptr;
	return T;
}

void find(bnd &T,int d){
	if(T==NULL)return;
	//cout<<T->data[0];
	for(int i=0;i<size;i++){
		if(T->data[i]==d){
			//cout<<" a "<<T->data[0];
			deletenode(T,d);
			return;
		}
	}
	if(d<T->data[0])return find(T->next[0],d);
	for(int i=0;i<size-1;i++){
		if(d>T->data[i]&&(d<T->data[i+1]||T->data[i+1]==0))return find(T->next[i+1],d);
	}
	return find(T->next[size],d);
}
	
void deletenode(bnd &T,int d){
	if(isleafnode(T)){
		int p;
		if(len_node(T)>size/2){
			//cout<<" a "<<T->data[0];
			int l = len_node(T);
			for(p=0;p<size&&T->data[p]!=d;p++);
			for(int i=p+1;i<l;i++){
				T->data[i-1]=T->data[i];
			}
			T->data[l-1]=0;
			
		}else{
			//cout<<T->pptr->data[2];
			if(isdelkeyred_leaf(T)){
				
				delkeyred_leaf(T,isdelkeyred_leaf(T),d);
				
			}
			
			else{
				
			if(T->pptr==root){
			
			mergedelete_internal(T,d);
			
			if(T->pptr->data[0]==0)root=T;
			}
			else{
				
				mergedelete_internal_utility(T,d);
			}
		}
			
	}
		return;
	}else{
		int y=isdelkeyred_internal(T);
		if(y){
			delkeyred_internal(T,y,d);
		}else{
			if(T->pptr==root){
			
			mergedelete_internal(T,d);
			if(T->pptr->data[0]==0)root=T;
			
			}		
			
			else{
				//cout<<" a ";
				mergedelete_internal_utility(T,d);
			}
		}
	}
	
	return;
}

void print(bnd b){
	if(b==NULL)return;
	int l=0;
	for(int i=0;i<size&&b->data[i]!=0;i++){
		cout<<b->data[i]<<" ";
	}
	for(int i=0;i<=size;i++)
	{	
		print(b->next[i]);

	}
	//cout<<b->next[1]->data[3];
}
int main(){
	int n;
	cout<<"Enter the number of elements ";
	cin>>n;
	bnd T=NULL;
	root=new(bnode);
	for(int i=1;i<n;i++){
		int d;
		
		//cin>>d;
		d=i;
		data=d;
		T=add(T);
		if(T->pptr!=NULL)
		T=T->pptr;
		root=T;
	}//print(root);
	//print(T);cout<<endl;
	find(T,4);
	//if(root!=NULL)T=root;
	//cout<<endl<<" After deletion ";
	print(T);	
}
