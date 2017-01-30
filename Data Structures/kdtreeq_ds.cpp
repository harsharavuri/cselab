#include<iostream>
#include<string.h>
using namespace std;
union data{
	char c[20];
	int a;
	char b;
	
};
const int size=3;
typedef struct node{
	data d[size];
	node* lchild;
	node* rchild;
}*bstptr;
node* insert(bstptr T,data d[],int size,int j){
	int key=j%size;j++;
	if(T==NULL){
		T=new(node);
		for(int z=0;z<size;z++)
		{
			if(z<size/3){
				T->d[z].a=d[z].a;
			}
			else if(z>=size/3&&z<2*size/3){
				
				T->d[z].b=d[z].b;
			}else if(z>=2*size/3&&z<size){
				cout<<d[z].c;
				strcpy(T->d[z].c,d[z].c);
				//cout<<"ddd";
			}
			//cout<<z;
			//cout<<"sss";
			T->lchild=T->rchild=NULL;
		}
	}else{
		if(key<size/3){
			cout<<key;
				if(T->d[key].a>d[key].a)
				return insert(T->lchild,d,size,++j);
				else{
					return insert(T->rchild,d,size,++j);
				}
			}
			else if(key>=size/3&&key<2*size/3){
				if(T->d[key].b>d[key].b){
					return insert(T->lchild,d,size,++j);}
					else
					return insert(T->rchild,d,size,++j);
				}
			else{
				if(strcmp(d[key].c,T->d[key].c)==1)
				return insert(T->rchild,d,size,++j);
				else
				return insert(T->lchild,d,size,++j);
			}
	}
	return T;
}
int search(bstptr T,data d[],int j){
	if(T==NULL)return 0;
	int key=j%size;
	if(key<size/3){
			//cout<<key;
				if(T->d[key].a==d[key].a){
					cout<<"Found";
					return 1;
				}
				if(T->d[key].a>d[key].a)
				return search(T->lchild,d,++j);
				else{
					return search(T->rchild,d,++j);
				}
			}
			else if(key>=size/3&&key<2*size/3){
				if(T->d[key].b==d[key].b){
					cout<<"Found";
					return 1;
				}
				if(T->d[key].b>d[key].b){
					return search(T->lchild,d,++j);}
					else
					return search(T->rchild,d,++j);
				}
			else{
				if(strcmp(T->d[key].c,d[key].c)==0){
					cout<<"Found";
					return 1;
				}
				if(strcmp(d[key].c,T->d[key].c)==1)
				return search(T->rchild,d,++j);
				else
				return search(T->lchild,d,++j);
			}
	}
	
	

int main(){
	//cout<<"ENter the size";
	//cin>>size;
	cout<<"ENter the number of elements ";
	int n;
	cin>>n;
	bstptr t;
	t=NULL;
	union data d[size];
	for(int i=0;i<n;i++){
	
	for(int i=0;i<size/3;i++){
		cin>>d[i].a;
	}
	for(int i=size/3;i<2*size/3;i++)
	cin>>d[i].b;
	for(int i=2*size/3;i<size;i++)
	cin>>d[i].c;
	//cout<<d[2].c;
	t=insert(t,d,size,1);
	}
	search(t,d,0);
}
