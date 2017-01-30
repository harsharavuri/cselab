#include<iostream>
#include<stack>
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
	temp = l;
	struct node* temp2;
	temp2=l;int k=1;
	stack<int> s;
	while(temp!=NULL&&temp->next!=NULL){

		temp=temp->next;
		
		temp = temp->next;
		s.push(temp2->data);
		temp2=temp2->next;
	}
		if(n%2==1)	
		temp2 = temp2->next;
	do{	
		int j=s.top();
		s.pop();
		cout<<j<<" "<<temp2->data<<endl;
		if(j!=temp2->data){
			cout<<endl<<"Not a palindrome ";
			return 0;
		}
		temp2 = temp2->next;
		
	}while(temp2!=NULL);
	cout<<"IT is a palindrome ";
	
	
}
