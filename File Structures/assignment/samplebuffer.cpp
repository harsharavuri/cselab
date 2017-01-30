#include<iostream>
#include<string.h>
using namespace std;
struct received{
	char a;
	char code[5];
};
union a;
struct leafnode{
	char data;
};
typedef struct node{
	char data;
	node* left;
	node* right;	
}*bstptr;
bstptr create(received a,bstptr &t){
	bstptr temp=new(node);
	temp=t;
	int i=0;
	while(a.code[i+1]!='\0'){
		if(a.code[i]=='0'){
			if(t->left==NULL){
			t->left=new(node);
			t->left->left=NULL;
			t->left->right==NULL;}
			t=t->left;
			//cout<<"  aa  ";
		}else{
			//cout<<" aa ";
			if(t->right==NULL){
			t->right=new(node);
			t->right->right=NULL;
			t->right->left=NULL;}
			t=t->right;
		}
		i++;
	}
	//cout<<" i "<<i;
	if(a.code[i]=='0'){
		//cout<<"  aa  ";
		if(t->left==NULL){
			t->left=new(node);
			t->left->left=NULL;
			t->left->right=NULL;
		}
		t=t->left;
		t->data=a.a;
		//t->left=t->right=NULL;
	}
	else{
		//cout<<"  a a ";
		if(t->right==NULL){
			t->right=new(node);
			t->right->left=NULL;
			t->right->left=NULL;
		}
		t=t->right;
		t->data=a.a;
		//t->left=t->right=NULL;
	}
	//return temp;
}
//union a{
//	node* left;
	
//};
void print(bstptr T){
	if(T==NULL)return;
	print(T->left);
	if(T->left==NULL&&T->right==NULL)cout<<T->data<<" ";
	print(T->right);
}
int main(){
	int n;
	bstptr t=new(node);
	t->left=t->right=NULL;
	cout<<"Enter the size of the elements ";
	cin>>n;
	received d[n];
	for(int i=0;i<n;i++){
		cout<<"Enter the chareceter and the code of the "<<i<<" th data ";
		cin>>d[i].a>>d[i].code;
		create(d[i],t);
		/*cout<<t->left<<"  "<<t->right<<"   ";
		t=t->left;
		cout<<t->left<<"  "<<t->right<<"  ";
		t=t->left;
		cout<<t->left<<"  "<<t->right<<"  ";*/ 
	}
	//print(t);
}
