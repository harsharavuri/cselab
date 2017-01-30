#include<iostream>
using namespace std;
struct branch{
	int key;
	int w;
	branch* next;
};
struct maino{
	int key;
	maino* down;
	branch* right;
};
maino* create_maino(maino* L,int key){
	maino* temp=new(maino);
	if(L==NULL){
		L=new(maino);
		L->key=key;
		L->down=NULL;
		L->right=NULL;
		return L;
	}else{
		temp=L;
		while(L->down!=NULL){
			L=L->down;
		}
		L->down=new(maino);
		L=L->down;
		L->key=key;
		L->down=NULL;
		L->right=NULL;
	}
	return temp;
}
branch* create_branch(branch* L,int key,int w){
	branch* temp=new(branch);
	if(L==NULL){
		L=new(branch);
		L->key=key;
		L->w=w;
		L->next=NULL;
		return L;
	}else{
		temp=L;
		while(L->next!=NULL){
			L=L->next;
		}
		L->next=new(branch);
		L=L->next;
		L->key=key;
		L->w=w;
		//L->down=NULL;
		L->next=NULL;
	}
	return temp;
}
void add_branch(maino* L,int ver,int b,int w){
	while(L->key!=ver&&L!=NULL)L=L->down;
	if(L==NULL){
		cout<<"Vertex not found ";return;
	}else{
		L->right=create_branch(L->right,b,w);
	}
}
int check(int key,int visited[][2]){
	int i=0;
	while(visited[i][0]!=key)i++;
	if(visited[i][1]==0){
		//cout<<i<<" ";
		visited[i][1]=1;
		return 1;
	}
	return 0;
}
int perfect(int visited[][2],int size){
	int i=0;
	while(i<size){
		if(visited[i][1]==0)return visited[i][0];i++;
	}
	return 0;
}
int n;
void print(maino* L){
	while(L!=NULL){
		branch* temp=L->right;
		cout<<L->key<<" -> ";
		while(temp!=NULL){
			cout<<temp->key<<" : "<<temp->w<<" -> ";
			temp=temp->next;
		}
		cout<<endl;
		L=L->down;
	}
}
int is_visited(int visited[][2],int key){
	for(int i=0;i<n;i++)if(visited[i][0]==key)if(visited[i][1]==0)return 0; return 1;
}
int min_get(maino* L,int visited[][2],int neighbours[],int &count){
	int min=10000;branch* temp;maino* t;
	int min_key=0;
	for(int i=0;i<count;i++){
		t=new(maino);t=L;
		while(t->key!=neighbours[i])t=t->down;
		temp=new(branch);temp=t->right;
		while(temp!=NULL){
			
			if(!is_visited(visited,temp->key)){
				if(min>temp->w){
					min=temp->w;
					min_key=temp->key;
					//cout<<"  a  ";
				}
			}
			temp=temp->next;
		}
	}
	int i=0;
	while(visited[i][0]!=min_key)i++;
	visited[i][1]=1;
	neighbours[count++]=min_key;
	cout<<"  "<<min;
	return 1;
	//count++;				
}
void prims_algorithm(maino* L,int visited[][2]){
	int count=0;
	int neighbours[n];
	neighbours[count++]=visited[0][0];
	//cout<<" "<<visited[0][0];
	visited[0][1]=1;
	while(count<n){
		min_get(L,visited,neighbours,count);
		//cout<<" a ";
	}
	//1 2 2 1 4 1 2 4 3 2 5 10 3 1 4 3 6 5 4 3 2 4 6 8 4 7 4 4 5 2 5 7 6 7 6 1
	//1 2 2 2 1 2 1 4 1 4 1 4 2 4 3 4 2 3 2 5 10 5 2 10 3 1 4 1 3 4 3 6 5 6 3 5 4 3 2 3 4 2 4 6 8 6 4 8 4 7 4 7 4 4 4 5 7 5 4 7 5 7 6 7 5 6 7 6 1 6 7 1
	//for(int i=0;i<count;i++)cout<<neighbours[i]<<" ";
}
int main(){
	cout<<"Enter the number of vertices ";
	//int n;
	cin>>n;
	maino *L;
	L=NULL;
	int visited[n][2];
	for(int i=0;i<n;i++){
		visited[i][1]=0;
	}
	for(int i=0;i<n;i++){
		int d;
		cout<<" Enter the vertex numbers ";
		cin>>d;
		L=create_maino(L,d);
		visited[i][0]=d;
	}
	cout<<"Enter the vertex number and the corresponding vertex to which it is attached and the weight";
	cout<<"\n Enter the vertex number as -1 to exit";
	int a,b,w;
	do{
		cin>>a>>b>>w;
		if(a==-1||b==-1)break;
		add_branch(L,a,b,w);
	}while(a!=-1&&b!=-1);
	//print(L);
	//cout<<n;
	prims_algorithm(L,visited);
	
}
