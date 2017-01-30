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
int main(){
	BSTPTR T=NULL;
	int n,d;
	cout<<"Enter the number of elements ";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>d;
		T=create(T,d);
	}
	print(T);
}
