#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
ofstream outf("output.txt");
struct node{
	node* next;
	int data;
	int size;
	node *a[5];
};
node *l;node *temp12;
void initnode(node* temp, int d){

	temp->data=d;
	temp->next=NULL;
}
void addnode(node* temp,int d){
	while(temp->next!=NULL){
		temp=temp->next;
	}	
	temp->next=new(node);
	temp=temp->next;
	temp->data=d;
	temp->next=NULL;
}
int input(struct node* temp, int si, int i){

	if(i==si){
		cout<<"THe graph has been sketched in the memory \n";
		return 0;
	}
	else if(i==0){
		cout<<"Enter the first element ";
		int d;cin>>d;
		initnode(temp,d);
		}
	else{
		cout<<"ENter the next element ";
		int d;
		cin>>d;
		addnode(temp,d);
	
		cout<<"Does it have any branches ";
		while(temp->next!=NULL){
			temp=temp->next;
		}
		cin>>temp->size;int y=0;
		if(temp->size>0){
			
			for(int j=0;j<temp->size;j++){
				cout<<"ENter the size of "<<j<<"th element ";
				int s;
				cin>>s;
				temp->a[j]=new(node);
				
				
				input(temp->a[j],s,y);
				
			}
		}
	}
	
	i++;
	return input(temp,si,i);
}

int find(node* temp, int k){
	if(temp==NULL)
	return 0;
	else{
		if(temp->size>0){
			if(temp->data==k){
				cout<<"Found";
				return 1;
			}
			for(int i=0;i<temp->size;i++){
				find(temp->a[i],k);
			}
			temp=temp->next;
		}
		else{
			if(temp->data==k){
				cout<<"Found";
				return 1;
			}
			temp=temp->next;
		}
	return find(temp,k);}
	
}
int print(node* temp){

	if(temp==NULL){
		return 0;
	}
	else {
		
		if(temp->size>0){
			cout<<temp->data<<" ";	
			for(int i=0;i<temp->size;i++){
				print(temp->a[i]);
			}
			temp=temp->next;
		}
		else{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		return print(temp);	
		
	}
	
	
}
int main(){
	cout<<"Enter the number of elements ";
	int n;
	cin>>n;
	l=new(node);
	temp12=new(node);
	temp12=l;
	int i=0;
	input(temp12,n,i);temp12=l;
	//find(l,3);
	print(l);
}

