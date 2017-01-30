#include<iostream>
using namespace std;
struct branch{
	int key;
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
branch* create_branch(branch* L,int key){
	branch* temp=new(branch);
	if(L==NULL){
		L=new(branch);
		L->key=key;
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
		//L->down=NULL;
		L->next=NULL;
	}
	return temp;
}
void add_branch(maino* L,int ver,int b){
	while(L->key!=ver&&L!=NULL)L=L->down;
	if(L==NULL){
		cout<<"Vertex not found ";return;
	}else{
		L->right=create_branch(L->right,b);
	}
}
void DFT(maino* L){
	//int s=search_list(visited[][],)
}
int main(){
	cout<<"Enter the number of vertices ";
	int n;
	cin>>n;
	maino *L;
	L=NULL;
	int visited[n][2];
	for(int i=0;i<n;i++){
		visited[i][1]=0;
	}
	for(int i=0;i<n;i++){
		int d;
		cout<<" Enter the vertex number ";
		cin>>d;
		L=create_maino(L,d);
		visited[i][0]=d;
	}
	cout<<"Enter the vertex number and the corresponding vertex to which it is attached ";
	cout<<"\n Enter the vertex number as -1 to exit";
	int a,b;
	do{
		cin>>a>>b;
		if(a==-1||b==-1)break;
		add_branch(L,a,b);
	}while(a!=-1&&b!=-1);
	DFT(L,visited);
}
