#include<iostream>
#include<fstream>
using namespace std;
typedef struct btnode{
	btnode* lchild;
	int data[2];
	btnode* rchild;
}*BSTPTR;

btnode* create(BSTPTR T, int d[],int size,int j){
	int key=j%size;j++;
	if(T==NULL){
		T=new(btnode);
		for(int z=0;z<2;z++)T->data[z]=d[z];
		
		T->lchild=NULL;
		T->rchild=NULL;
	}else if(d[key]<=T->data[key])T->lchild=create(T->lchild,d,size,j);
	else T->rchild=create(T->rchild,d,size,j);
	return T;
}
BSTPTR kdsearch(BSTPTR T,int k[],int s,int j){
	int flag=1;
	if(T==NULL)return NULL;
	else{
		int i=0;
		for(int i=0;i<s;i++){
			if(k[i]==T->data[i])
			flag=1;
			else flag=0;
		}
		if(flag==1)cout<<"Found";
	
	}
	int check = j%s;j++;
	if(T->data[check]>k[check])T->lchild=kdsearch(T->lchild,k,s,j);
	else
	T->rchild=kdsearch(T->rchild,k,s,j);
	return T;
}
void print(BSTPTR T){
	if(T==NULL)return;
	print(T->lchild);
	for(int i=0;i<2;i++)
	cout<<T->data[i];
	cout<<endl;
	print(T->rchild);
}
int main(){
	BSTPTR T=new(btnode);
	int d[2];
	T=NULL;
	for(int i=0;i<4;i++){
		for(int j=0;j<2;j++)
		cin>>d[j];
		T=create(T,d,2,0);
		
	}
	d[0]=1;d[1]=3;
	//print(T);
	kdsearch(T,d,2,0);
}
