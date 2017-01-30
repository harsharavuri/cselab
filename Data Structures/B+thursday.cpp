// Sri Harsha Aditya
// Roll no:147241
//Check btree_check_it_later lines:197 ... //
#include<iostream>
using namespace std;
const int size = 2;
struct bnode;
union nxt{
	bnode* next[size+1];
	bnode* right;
};
typedef struct bnode{
	int count=0;
	int data[size];
	union nxt next;
	int tag;
	bnode* pptr;
	node_cons(){
		for(int i=0;i<size;i++){
			data[i]=0;
			//count=0;
			tag=-1;
			next.next[i]=NULL;
		}
		next.next[size]=NULL;
		next.right=NULL;
	}
}*bnd;

int data;
bnd tt=NULL;
bnd root=NULL;
class queue{
	//int ele[25];
	bnd elements[25];
	int size;
	int front;
	int rear;
	public:
	
	queue(){
		size = 25;
		rear=-1;
		front=-1;
	}
	int isempty(){
		if(front==-1)return 1;
		else return 0;
	}
void enqueue(bnd &d){
	
	if(rear==-1){
		front++;
		rear++;
		elements[rear]=d;
		
	}
	else if(front==(rear+1)%size){
		
		cout<<"Size limit reached ";
	}
	else{
		
		rear=(rear+1)%size;
		elements[rear]=d;
	}
}
bnd dequeue(){
	if(front==-1){
		cout<<"The queue is empty ";
		return 0;
	}
	else if(front==rear){
		bnd temp=elements[rear];
		rear=front=-1;
		return temp;
	}
	else{
		int temp=front;
		front=(front+1)%size;
		return elements[temp];
	}
}
bnd top(){
	return elements[front];
}

};



void sort(int a[],int size){
	for(int i=0;i<size;i++){
		int min=a[i];
		for(int j=i;j<size;j++){
			if(a[j]<min){
				int temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
}
/*int check_key_red(bnd &T){
	if(T->pptr==NULL)return -1;
	else{
		for(int i=0;i<=size&&T->pptr->next[i]!=NULL;i++){
			if(T->pptr->next[i]!=NULL){
				for(int j=0;j<size;j++)
				if(T->pptr->next[i]->data[j]==0)
				return i;
			}
		}
	}
	return -1;
}
int find_ptr(bnd &T){
	bnd temp=new(bnode);
	temp=T->pptr;
	for(int i=0;i<=size;i++){
		if(temp->next[i]->data[0]==T->data[0])
		return i;
	}
}
int key_red(bnd &T,int i,int j){
	int store;
	int a[size];
	
	if(i<j){
		store=T->next[i]->data[size-1];
		for(int k=0;k<size-1;k++)a[k]=T->next[i]->data[k];
		a[size-1]=data;
		for(int m=0;m<size;m++){
				int min=a[m];
				for(int n=m;n<size;n++){
					if(min>a[n]){
						int temp=a[n];
						a[n]=a[m];
						a[m]=temp;
					}
				}
			}
		
		for(int k=j;k>i;k--){
			if(k==j){
				int y;
				for(y=0;y<size&&T->next[k]->data[y]!=0;y++);y--;
				for(int l=y;l>=0;l--)T->next[k]->data[l+1]=T->next[k]->data[l];
				T->next[k]->data[0]=T->data[k-1];
			}
			else{
				T->data[k]=T->next[k]->data[size-1];
				for(int l=size-2;l>=0;l--)T->next[k]->data[l+1]=T->next[k]->data[l];
				T->next[k]->data[0]=T->data[k-1];
			}
			
		}
		T->data[i]=store;
		for(int k=0;k<size;k++)T->next[i]->data[k]=a[k];
	}else{
		for(int k=j;k<i;k++){
			if(k==j){
				int y;
				for(y=0;y<size&&T->next[k]->data[y]!=0;y++);
				//for(int l=y;l>0;l--)T->next[k]->data[l+1]=T->next[k]->data[l];
				T->next[k]->data[y]=T->data[k];
			}
			else{
				T->data[k-1]=T->next[k]->data[0];
				for(int l=0;l<size-1;l++)T->next[k]->data[l]=T->next[k]->data[l+1];
				T->next[k]->data[size-1]=T->data[k];
			}
		
		}		
			for(int k=1;k<=size-1;k++)a[k]=T->next[i]->data[k];
			a[0]=data;
			sort(a,size);
			for(int m=0;m<size;m++){
				int min=a[m];
				for(int n=m;n<size;n++){
					if(min>a[n]){
						int temp=a[n];
						a[n]=a[m];
						a[m]=temp;
					}
				}
			}
			//cout<<a[0]<<a[1]<<a[2]<<a[3]<<"   ";
			T->data[i-1]=T->next[i]->data[0];
			for(int k=0;k<size;k++)T->next[i]->data[k]=a[k];
	}
}
*/
void sort_node(bnd ab[],int size){
	int i=0;
	int j=0;
	for(int j=0;j<=size+1&&ab[j]!=NULL;j++);
	//if(data==6&&ab[0]!=NULL)cout<<j;
	for(int i=0;i<j;i++){
		bnd min=new(bnode);min=ab[i];
		for(int k=i;k<j;k++){
			if(ab[k]->data[0]<min->data[0]){
				bnd temp=new(bnode);
				temp=ab[k];
				ab[k]=ab[i];
				ab[i]=temp;
			}
		}
	}
}
bnd node_splitting(bnd &T){
	//if(data==15)cout<<T->next[0]<<"  ";
	bnd temp=new(bnode);int k=0;
	temp->node_cons();
	int a[size+1];
	for(int i=0;i<size;i++){
		a[i]=T->data[i];
	}

	a[size]=data;
	sort(a,size+1);
	for(int i=0;i<size/2;i++)T->data[i]=a[i];
	if(T->next.next[0]==NULL){
		temp->data[k]=a[size/2];k++;
	}
	for(int i=size/2+1;i<=size;i++){
			
		temp->data[k]=a[i];k++;
		T->data[i-1]=0;
		//if(data==15)cout<<T->next[0]<<"  ";
	}
			//if(data==15)cout<<T->next[0]<<"  ";
	//T->data[size/2]=0;
	data=a[size/2];
	bnd ab[size+2];
	//if(data==15)
	//cout<<data<<" ";
	//if(data==15)cout<<T->next[0]<<"  ";
	if(T->next.next[0]!=NULL){
		//cout<<"  a  ";
		for(int i=0;i<=size;i++)
		{
			ab[i]=new(bnode);
			ab[i]=T->next.next[i];
		}
		ab[size+1]=NULL;
		if(tt!=NULL){
		tt->pptr=temp;
		ab[size+1]=tt;
		
		}
	
		sort_node(ab,size);
		for(int i=0;i<=size/2;i++){
			//if(data==6)cout<<T->next[size/2]->data[0];
			T->next.next[i]=ab[i];
			if(T->next.next[i]!=NULL)T->next.next[i]->pptr=T;
		}
		//T->next[size/2]=NULL;
		T->next.next[size/2+1]=NULL;
		k=0;
		for(int i=size/2+1;i<size+1;i++){
			temp->next.next[k]=new(bnode);
			*temp->next.next[k] = *ab[i];
			temp->next.next[k]->pptr=NULL;
			if(temp->next.next[k]!=NULL){
			temp->next.next[k]->pptr=new(bnode);
			temp->next.next[k]->pptr=temp;
			}
			k++;
			T->next.next[i]=NULL;	
		}
		/*if(ab[size+1]!=NULL)*/temp->next.next[k]=ab[size+1];
		if(temp->next.next[k]!=NULL){
			bnode te;te=*ab[size+1];te.pptr=NULL;*temp->next.next[k]=te;
		temp->next.next[k]->pptr=new(bnode);
		temp->next.next[k]->pptr=temp;
	
		}
	}
	//if(data==15)cout<<T->data[0]<<temp->data[0]<<" bbb ";
	//T->data[size/2]=0;
	data=a[size/2];
	tt=NULL;
	return temp;
}
//bnd root;
bnd insert_and_sort(bnd &T,int size){
	//if(data>=6)return T;
	
	//if(data==7)cout<<"yeas";
	if(T==NULL){
		//cout<<"data"<<data<<"  ";
		T=new(bnode);
		T->node_cons();
		T->data[0]=data;
		T->pptr=NULL;
		tt->pptr=T;
		//cout<<tt->data[0]<<" ";
		T->next.next[1]=new(bnode);
		T->next.next[1] = tt;
		tt=NULL;
		root=T;
		return T;
	}else{
		int l;
		//cout<<data;
		for(l=0;l<size&&T->data[l]!=0;l++);
		int a[size+1];
		for(int i=0;i<l;i++){
			a[i]=T->data[i];
		}
		//if(l==size)a[size]=data;
		//if(data==7)
		//cout<<T->data[size-1];
		//return NULL;
		bnd ab[size+2];
		for(int i=0;i<size+2;i++){
			ab[i]=NULL;
		}
		for(int i=0;i<=l;i++){
			ab[i]=new(bnode);
			ab[i]=T->next.next[i];
			}
			//if(data==9)cout<<T->data[0]<<" "<<T->data[1]<<" "<<T->data[2]<<" "<<T->data[3]<<" ";
			//ab[l]=0;
			//ab[l+1]=0;
			ab[l+1]=NULL;
			if(tt!=NULL){
			ab[l+1]=new(bnode);
			tt->pptr=T;
			ab[l+1]=tt;
			//cout<<ab[2]->data[0];
			tt=NULL;
			}
			sort_node(ab,size);
			if(l<size){
				for(int i=0;i<=l+1;i++)
				T->next.next[i]=ab[i];
				//if(data==8)cout<<"yeah";
				a[l]=data;
				sort(a,l+1);
				//if(data==6)
				//cout<<a[0];
				for(int i=0;i<=l;i++)T->data[i]=a[i];
				//for(int i=0;i<=l;i++)
				//cout<<l;
				//if(data==7)cout<<T->data[2]<<T->data[3]<<" ";
			}else{
				/*int check=check_key_red(T);
				if(check!=-1){
					//cout<<"  a  ";
					int ptr = find_ptr(T);
					key_red(T->pptr,ptr,check);
					//cout<<ptr<<" "<<check<<" ";
					return T;
				}*/
				
				
				//cout<<l;
				//return T;
				//if(data==8)cout<<"a";
				for(int i=0;i<=l;i++)T->next.next[i]=ab[i];
				tt=ab[size+1];bnd t1=new(bnode);
				int yl=0;
				if(data==15)yl=1;
				//if(yl)cout<<T->next[0]->data[0]<<"  ";
				t1=node_splitting(T);
				//if(yl){ cout<<t1->next[0];} //cout<<data<<" ";
				//if(data==15)cout<<T->data[0]<<T->data[1]<<"  "<<t1->data[0]<<"  ";
				//if(data==6)cout<<T->pptr->next[1]->data[1]<<"   ";
				tt=new(bnode);
				tt=t1;int flag=0;
				//if(data==15)cout<<tt->data[0]<<" ";
				if(T->pptr==NULL)flag=1;
				
				T->pptr=insert_and_sort(T->pptr,size);
				//if(data==9)cout<<"  "<<T->data[0]<<"   ";
				if(flag){
				//if(data==6)cout<<"aa ";	
				if(T->pptr!=NULL){
					T->pptr->next.next[0]=new(bnode);
					T->pptr->next.next[0]=T;
					if(T->pptr->next.next[1]!=NULL)T->pptr->next.next[1]->pptr=T->pptr;
					//return T->pptr;
					}
				}//cout<<T->data[0]<<"  "<<T->pptr->data[0]<<"  "<<T->pptr->next[1]->data[0]<<"  ";
			}
		
		return T;
	}
}
bnd add(bnd &T){
if(T==NULL){
		T=new(bnode);
		T->node_cons();
		T->data[0]=data;
		
		T->count++;
		T->pptr=NULL;
		//cout<<T->data[0];
		return T;
	}
	if(data<T->data[0]&&T->next.next[0]!=NULL){
	
		T->next.next[0]=add(T->next.next[0]);
		if(T->next.next[0]!=NULL)T->next.next[0]->pptr=T;
		return T;
	}
	int yf=0;
	for(int i=0;i<size-1;i++){
		
		if(data>T->data[i]&&(data<T->data[i+1]||T->data[i+1]==0)&&T->next.next[i+1]!=NULL)
		{	//if(data==18)
			//{
			//cout<<"  enter "<<T->data[0];	
			//}
			T->next.next[i+1]=add(T->next.next[i+1]);
			if(T->next.next[i+1]!=NULL)T->next.next[i+1]->pptr=T;
			return T;
		}
		
	}
	
		
	if(data>T->data[size-1]&&T->next.next[size]!=NULL)
	{	//if(data==15)cout<<" a ";
	T->next.next[size]=add(T->next.next[size]);
	//if(T->next[size]!=NULL)T->next[size]->pptr=T->pptr;	
	return T;
	}
		
	T=insert_and_sort(T,size);
		
	//if(T->pptr!=NULL)return T->pptr;
	return T;
}
void print(bnd b){
	if(b==NULL)return;
	int l=0;
	for(int i=0;i<size&&b->data[i]!=0;i++){
		cout<<b->data[i]<<" ";
	}
	//print(b->next.next[0]);
	for(int i=0;i<=size&&b->tag!=0;i++)
	{	//if(b->tag!=0)
		print(b->next.next[i]);
	}
	//cout<<b->next[1]->data[3];
	}
void print_leaf(bnd b){
	while(b->tag!=0)b=b->next.next[0];
	//cout<<b->data[0];
	while(b!=NULL){
		for(int i=0;i<size&&b->data[i]!=0;i++)
		cout<<b->data[i];
		b=b->next.right;
	}
}
int p[size];
void initialise_print(){

for(int i=0;i<size;i++)p[i]=-1;
}
int checkprint(int a){
	for(int i=0;i<size&&p[i]!=-1;i++)if(p[i]==a)return 1;
	return 0;
}
void print_range_searching(bnd b,int k1,int k2){
	if(b==NULL)return;
	for(int i=0;i<size;i++){
		if(b->data[i]>k1&&b->data[i]<k2){
		if(!checkprint(b->data[i])){
			//cout<<"a";
			cout<<b->data[i]<<"  ";
			int k=0;
			while(p[k]!=-1)k++;
			p[k]=b->data[i];
		}
		
		}
	}
	if(b->tag!=0){
		
		if(b->data[0]<=k2)print_range_searching(b->next.next[0],k1,k2);
		for(int i=0;i<size-1;i++)
		if(b->data[i]>k1&&b->data[i+1]<k2)print_range_searching(b->next.next[i+1],k1,k2);
		if(b->data[size-1]<=k1)print_range_searching(b->next.next[size],k1,k2);
	}
}
void print_level_order(queue &q){
	bnd temp=new(bnode);
	temp->node_cons();
	temp->data[0]=-2;
	q.enqueue(temp);
	while(!q.isempty()&&q.top()->tag!=0){
		bnd t=new(bnode);
		t=q.dequeue();
		for(int i=0;i<size&&t->data[i]!=0;i++)
		cout<<t->data[i]<<" ";
		cout<<" # ";
		for(int i=0;i<=size&&t->next.next[i]!=NULL;i++)
		q.enqueue(t->next.next[i]);
		if(q.top()->data[0]==-2){
			cout<<endl;
			q.dequeue();
			q.enqueue(temp);
		}
	}
	while(!q.isempty()&&q.top()->data[0]!=-2){
		bnd t=new(bnode);
		t=q.dequeue();
		for(int i=0;i<size&&t->data[i]!=0;i++)
		cout<<t->data[i]<<" ";
		cout<<" # ";
	}
}
int main(){
	int n;
	cout<<"Enter the number of elements ";
	cin>>n;
	bnd T=NULL;
	root=new(bnode);
	for(int i=1;i<n;i++){
		int d;
		
		//cin>>d;
		d=i;
		data=d;
		T=add(T);
		if(T->pptr!=NULL)
		T=T->pptr;
		//root=T->pptr;
	}
	queue q;
	q.enqueue(T);
	//cout<<T->data[2];
	while(!q.isempty()&&q.top()->next.next[0]!=NULL){
		bnd t=new(bnode);
		t=q.dequeue();
		for(int i=0;i<=size&&t->next.next[i]!=NULL;i++)
		q.enqueue(t->next.next[i]);
	}
	//print(T);
	bnd t1=new(bnode);bnd t2=new(bnode);
	if(!q.isempty()){
	
	t1=q.dequeue();
	t1->tag=0;
	}
	while(!q.isempty()){
		
		t2=q.dequeue();
		t2->tag=0;
		t1->next.right=new(bnode);
		t1->next.right=t2;
		//t2->next.right=NULL;
		t1=t2;
	    t1->tag=0;
	}
	t1->next.right=NULL;
	queue q1;
	initialise_print();
	q1.enqueue(T);
	//print_level_order(q1);
	//print_leaf(T);
	print_range_searching(T,1,4);
}
