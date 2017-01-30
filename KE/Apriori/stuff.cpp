#include<iostream>
using namespace std;


struct node{
	int data;
	node* left;
	node* right;
};

node* insert(node* temp, int data){
	if(temp==NULL){
		temp = new(node);
		temp->data=data;
		temp->left=temp->right=NULL;
	}else{
		if(data<temp->data)temp->left=insert(temp->left,data);
		else temp->right = insert(temp->right, data);
	}
	return temp;
}

void print(node* temp){
	if(temp==NULL)return;
	print(temp->left);
	cout<<temp->data<<"  ";
	print(temp->right);
}

int modify(node* & temp){
	
	if(temp==NULL)return 0;
	int a = modify(temp->left);
	int b=modify(temp->right);
	int original=temp->data;
	if(a+b > 0)temp->data=a+b;
	if(a+b == 0)return temp->data;
	else return a+b+original;

}

int main(){
	node* L=NULL;
	int data;
	cin>>data;
	while(data!=-1){
		L = insert(L, data);
		cin>>data;
	}
	print(L);
	cout<<endl;
	modify(L);
	print(L);
}
