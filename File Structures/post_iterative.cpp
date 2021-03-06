#include<iostream>
using namespace std;
typedef struct btnode{
	btnode* lchild;
	int data;
	btnode* rchild;
}*BSTPTR;
btnode *create(BSTPTR t,int d){
	if(d==-1)t=NULL;
	else{
		t=new(btnode);
		t->data=d;
		int l,r;
		cout<<"Enter left and right children ";
		cin>>l>>r;
		t->lchild=create(t->lchild,l);
		t->rchild=create(t->rchild,r);
	}
	return t;
}
class stack{
	int size;
	int top;
	BSTPTR a[30];
	public:
		stack(){
			top=-1;size=25;
		}
		//void set_size(int x)size=x;
		int push(BSTPTR x){
			++top;
			if(top<size){
				a[top]=x;return 1;
			}
			else{
				top--;
				cout<<"Size limit reached ";
				return 0;
			}
		}
		BSTPTR pop(){
			if(top==-1){
				cout<<"Array is empty ";return 0;
			}else
			return a[top--];
		}
		int isempty(){
			if(top==-1)
			return 1;
			else
			return 0;
		}
	
};
stack s1,s2;
void print(BSTPTR T){
	if(T==NULL)return;
	print(T->lchild);
	cout<<T->data<<" ";
	print(T->rchild);
}
void inorder(BSTPTR T){
	while(!s1.isempty()){
		if(T==NULL){
			T=s1.pop();
			cout<<T->data<<" ";
			if(T->rchild!=NULL){
				s1.push(T->rchild);
				
			}
			T=T->rchild;
		}
		else{
			if(T->lchild!=NULL)
			s1.push(T->lchild);
			T=T->lchild;
		}
	}
}
void preorder(BSTPTR T){
	while(!s1.isempty()){
		if(T==NULL){
			T=s1.pop();
		
			if(T->rchild!=NULL){
				s1.push(T->rchild);
				
			}
			T=T->rchild;
		}
		else{
			cout<<T->data<<" ";
			if(T->lchild!=NULL)
			s1.push(T->lchild);
			T=T->lchild;
		}
	}
}
void postorder_iterative(BSTPTR T){
	if(T==NULL)
	return;
	stack s1,s2;
	s1.push(T);
	while(!s1.isempty()){
		BSTPTR temp=new(btnode);
		temp=s1.pop();
		if(temp->lchild!=NULL)
		s1.push(temp->lchild);
		if(temp->rchild!=NULL)
		s1.push(temp->rchild);
		s2.push(temp);
	}
	while(!s2.isempty()){
		BSTPTR temp=new(btnode);
		temp=s2.pop();
		cout<<temp->data;
	}
}
int main(){
	BSTPTR T;
	T=new(btnode);
	T=create(T,4);
	//s1.push(T);
	//print(T);
	//preorder(T);
	postorder_iterative(T);
}
