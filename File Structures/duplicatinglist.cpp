#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
};
void remove1(struct node *temp,int i){
	for(int j=0;j<i-1;j++){
		temp=temp->next;
	}
	
	temp->next=temp->next->next;
}
void print(node* temp){
	while(temp->next!=NULL){
		cout<<temp->data;
		temp=temp->next;
	}
}

int remove_node(struct node *l,int i){
	
	
	struct node* temp=new(node);
	temp=l;
	
	int j=0;
	while(j<i){
		temp=temp->next;
		j++;
	}

		if(temp->next==NULL){
		
		return 0;
	}


	node* temp1=new(node);
	temp1=temp->next;j++;
	while(temp1->next!=NULL){
		if(temp1->data==temp->data){
	
		remove1(l,j);
		
		}
		else
		{
			j++;
		}
		temp1=temp1->next;
	}
	i++;
	
	return remove_node(l,i);
}


int main(){
	cout<<"Enter the number of elements ";
	int n;
	cin>>n;
	node* l = new(node);
	node* temp=new(node);
	temp=l;
	for(int i=0;i<n;i++){
		temp->next=new(node);
		cin>>temp->data;
		temp=temp->next;
		temp->next=NULL;
	}
	temp=l;
	remove_node(l,0);
	print(temp);
}
