#include<iostream>
using namespace std;
typedef struct node{
	int data;
	node* next;
	//node* rchild;
	
}*BSTPTR;

void insert(int H[],int n,int i){
	
}

void add(int H[],int n,int i,int k){
	if(i<=n){ H[i]=k;
		while(H[i]<H[i/2]&&i>0){
			int temp=H[i];
			H[i]=H[i/2];
			H[i/2]=temp;
			i=i/2;
		}
	}else
	return;
}
printll(node* t){
	while(t!=NULL){
		cout<<t->data;
		t=t->next;
	}
}
int del(int H[],int n){
	int i=1;int k= H[i];
	if(n>0){	
			
			
			H[i]=H[n];
			while(2*i<=n&&(H[i]>H[2*i]||H[i]>H[2*i+1])){
					if((H[2*i]<H[2*i+1])||2*i+1>n)
					{
					if(H[i]>H[2*i]){
					
					int temp=H[i];
					H[i]=H[2*i];
					H[2*i]=temp;
					i=2*i;
					}
					}
				
			
				else if(2*i<=n){
					
					{
					int temp=H[i];
					H[i]=H[2*i+1];
					H[2*i+1]=temp;
					i=2*i+1;}
			}
	}
		return k;	
	}
else
return 0;}
void print(int H[],int n){
	for(int i=1;i<=n;i++)
	cout<<H[i]<<" ";
}
int main(){
	int H[10];
	int n;
	cin>>n;
	node *T;
	T=NULL;
	for(int i=1;i<=n;i++){
		int d;
		cin>>d;
		add(H,n,i,d);
	}
	del(H,n);n--;
	print(H,n);cout<<endl;
		
}
