#include<iostream>
#include<stdio.h>
using namespace std;
struct node{
	int data;
	struct node* next;
	struct node* random;
};
int main(){
	cout<<"Enter the number of elements ";
	int n;
	cin>>n;
	node* l;
	node* temp;
	l=new(node);
	temp=new(node);
	temp=l;
	for(int i=0;i<n;i++){
		temp->next=new(node);
		cin>>temp->data;
		temp=temp->next;
		temp->next=NULL;
	}
	temp=l;
	node* temp1;node* replica;node* duplicate;temp1=replica=duplicate=new(node);
	replica=duplicate;
	replica->next=NULL;

	temp=l;
	while(temp->next!=NULL){
		replica->data=temp->data;
		replica->next=new(node);
		replica->random=NULL;
		replica=replica->next;
		replica->next=NULL;
		temp=temp->next;
	}
	temp=l;
	temp1=duplicate;
	while(temp!=NULL){
		replica=duplicate;
		while(replica->next!=NULL){
			if(replica->data==temp->data){
				temp1->random=replica->random;
				
			}
			replica=replica->next;
		}
		temp=temp->next;
		temp1=temp1->next;
	}
}
