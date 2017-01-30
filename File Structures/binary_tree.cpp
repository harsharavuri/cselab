#include<iostream>
using namespace std;
typedef struct btnode{
	btnode* lchild;
	int data;
	btnode* rchild;
}*BSTPTR;
class queue{
	int rear;
	int size;
	BSTPTR elements[50];
	int front;
	public:
		queue(){
			rear=-1;
			front=-1;
			size = 25;
		}
	void enqueue(BSTPTR a){
		if(front==-1){
			front++;
			elements[front]=a;
			rear++;
		}
		else if(front==(rear+1)%size){
		cout<<"Size limit reached ";
		}
		else{
			elements[rear]=a;
			rear=(rear+1)%size;
		}
		
	}
	BSTPTR dequeue(){
		
		if(front==-1){
			cout<<"Empty ";
			return 0;
		}
		else if(rear==front){
			int temp=front;
			front=rear=-1;
			return elements[temp];
		}
	
		else{
			int temp=front;
			front=(front+1)%size;
			return elements[temp];
		}
	}
	int fr(){
		return front;
	}
};
btnode *create(BSTPTR t,int d){
	if(d==-1)t=NULL;
	else{
		t=new(btnode);
		t->data=d;
		int l,r;
		cout<<"Enter left and right children ";
		cin>>l>>r;
		t->lchild=create(t->lchild,l);
		t->rchild=create(t->rchild,r);
	}
	return t;
}
void print(BSTPTR T){
	if(T==NULL)return;
	print(T->lchild);
	cout<<T->data<<" ";
	print(T->rchild);
}
void levelprint(queue &q){
	if(q.fr()==-1)
	return;
	BSTPTR temp=new(btnode);
	temp->data=-2;
	temp->lchild=temp->rchild=NULL;
	BSTPTR k=new(btnode);
	k=q.dequeue();
	if(k->data==-2){
		if(q.fr()==-1)return;
		cout<<endl;
		q.enqueue(temp);
		return levelprint(q);
	}
	cout<<k->data<<" ";
	if(k->lchild!=NULL)q.enqueue(k->lchild);
	if(k->rchild!=NULL)q.enqueue(k->rchild);
	return levelprint(q);
}
int main(){
	BSTPTR T=NULL;
	
	T=create(T,4);
	//print(T);
	queue q;
	BSTPTR temp=new(btnode);
	temp->data=-2;
	temp->lchild=temp->rchild=NULL;
	q.enqueue(T);
	q.enqueue(temp);
	cout<<q.fr();
	levelprint(q);
}
