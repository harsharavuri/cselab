#include<iostream>
using namespace std;
typedef struct btnode{
	btnode* lchild;
	int data;
	btnode* rchild;
}*BSTPTR;
btnode* create(BSTPTR T, int data){
	if(T==NULL){
		T=new(btnode);
		T->data=data;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	else if(data<=T->data)T->lchild=create(T->lchild,data);
	else if(data>T->data)T->rchild = create(T->rchild,data);
	return T;
}
void print(BSTPTR T){
	if(T==NULL)return;
	print(T->lchild);
	cout<<T->data<<" ";
	print(T->rchild);
}
int min(BSTPTR T){
	if(T->lchild==NULL)return T->data;
	return min(T->lchild);
}
BSTPTR delete1(BSTPTR T,int d){
	if(T->data==d){
		if(T->lchild&&T->rchild==NULL)return NULL;
		if(T->lchild==NULL)return T->rchild;
		if(T->rchild==NULL)return T->lchild;
		int k = min(T->rchild);
		T->data=k;
		T->rchild=delete1(T->rchild,k);
	}
	else{
		if(d<T->data)T->lchild=delete1(T->lchild,d);
		else
		T->rchild=delete1(T->rchild,d);
	}
	return T;
}
int main(){
	BSTPTR T=NULL;
	int n,d;
	cout<<"Enter the number of elements ";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>d;
		T=create(T,d);
	}
	delete1(T,3);
	print(T);
}
