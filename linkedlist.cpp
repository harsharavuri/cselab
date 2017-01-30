#include<iostream>
#include<string.h>
using namespace std;
struct node{
	int data;
	struct node* next;
};
void remove_node(struct node* temp){
	if(temp==NULL){
		cout<<"No node to remove ";
		return;
	}
	while(temp->next->next!=NULL){
		temp = temp->next;
	}
	temp->next=NULL;
}
void add_node_end(struct node* temp){
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new(node);
	cout<<"Enter the value of the element";
	temp=temp->next;
	cin>>temp->data;
	temp->next=NULL;
}

void print(struct node* temp){
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}
int main(){
	
	struct node* l; struct node* temp;
	
	l=new node;
	l->next=NULL;
	temp = new(node);
	temp=l;

	cout<<"\n Enter the number of elements you want to enter ";
	int n;
	cin>>n;
	if(n>0){
	
		cout<<"Enter the data";
		cin>>temp->data;
		temp->next=NULL;
	}
	for(int i=0;i<n-1;i++){
		add_node_end(temp);
		temp =l;
	}
}
