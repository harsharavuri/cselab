#include<iostream>
using namespace std;
const int size=3;
typedef struct node{
	int data[size];
	node* child[2];
	node* pptr;
	int j;
}*BSTPTR;
class queue{
	private:
		BSTPTR elements[25];
		int size;
		int front;
		int rear;

public:
	queue(){
		rear=front=-1;
		size=25;
	}
void enqueue(BSTPTR d){
	if(rear==-1){
		front++;rear++;elements[rear]=d;
	}else if(front==(rear+1)%size)cout<<"Size limit reached ";
	else{
		rear=(rear+1)%size;
		elements[rear]=d;
	}
}
BSTPTR dequeue(){
	if(front==-1)cout<<"Queue is empty ";
	else if(front==rear){
		int temp=rear;
		rear=front=-1;
		return elements[temp];
	}
	else{
		int temp=rear;
		front=(front+1)%size;
		return elements[temp];
	}
}
int isempty(){
	if(front==-1)return 1;
	else
	return 0;
}
};
queue q;
void create(BSTPTR &T){
	int i,j,k;int flag;int b[3];BSTPTR h=new(node);
	T->pptr=NULL;
	T->j=0;
	for(int i=0;i<3;i++)
	cin>>T->data[i];
	T->child[0]=T->child[1]=NULL;
	q.enqueue(T);
	flag=1;
	cout<<"Enter -1 to stop ";
	cin>>flag;
		while(q.isempty()!=1&&flag!=-1){
			h=q.dequeue();
			for(int i=0;i<2;i++){
			BSTPTR x=new(node);h->child[i]=new(node);x=h->child[i];	
			for(int l=0;l<3;l++){
				cin>>b[l];
				x->data[l]=b[l];
			}
			
				x->j=(h->j+1)%size;
				x->pptr=h;
				x->child[0]=NULL;//T->lchild->data=-1;
				x->child[1]=NULL;//T->rchild->data=-1;

				BSTPTR check=new(node);check=x->pptr;
				while(check!=NULL){
					if(x->data[check->j]<check->data[check->j]){
						for(int z=0;z<3;z++){
							int temp=x->data[z];
							x->data[z]=check->data[z];
							check->data[z]=temp;
							cout<<"entering ... ";
						}
					}
					check=check->pptr;x=x->pptr;
				}
				x=h->child[i];
				q.enqueue(x);
		}
		cout<<"Do you want to continue ";
		cin>>flag;
	}
}
int check(BSTPTR T){
	int chek;
	if(T==NULL)return 1;
	else if(T->pptr!=NULL){
		if(T->data[T->pptr->j]<T->pptr->data[T->pptr->j])return 0;
	}
	else{
		for(int i=0;i<3;i++){
			chek=check(T->child[i]);
			if(chek==0)return 0;
		}
	}
	return 1;
}
void print(BSTPTR T){

	if(T->child[0]!=NULL)print(T->child[0]);
	if(T->child[1]!=NULL)print(T->child[1]);
	{
		for(int i=0;i<3;i++)cout<<T->data[i];
		cout<<endl;
	}
}
int main(){
	BSTPTR T=NULL;
	T=new(node);
	create(T);
	print(T);
	cout<<"  ... CHECK ... "<<check(T);
}
