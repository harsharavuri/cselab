#include<iostream>
using namespace std;
int **A,n,trak=0;
int *visited,*low,*parent;
struct edge{
	int a;
	int b;
};
int track=0;
	class stack{
		
	private:
		int size;
		int a[25];
		int top;
	public:
		stack(){
			top = -1;size=25;
		}
		void set_size(int x)
		{
			size = x;
		}	
		int push(int x)
		{	++top;
			if(top<size)
			{
			a[top] = x;return 1;}
			else
			{top--;
			cout<<"Size limit reached";return 0;}}
		int pop()
		{
			if(top==-1)
			{
			cout<<"Array is empty"
			;}
			else
			return a[top--];
		}
		int topp(){
			return a[top];
		}
		void print()
		{
			for(int i=0;i<=top;i++)
			cout<<a[i]<<" ";
		}
		int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
};
class stak{
		
	private:
		int size;
		edge a[25];
		int top;
	public:
		stak(){
			top = -1;size=25;
		}
		void set_size(int x)
		{
			size = x;
		}	
		int push(edge x)
		{	++top;
			if(top<size)
			{
			a[top] = x;return 1;}
			else
			{top--;
			cout<<"Size limit reached";return 0;}}
		edge pop()
		{
			if(top==-1)
			{
			cout<<"Array is empty"
			;}
			else
			return a[top--];
		}
		edge topp(){
			return a[top];
		}
		int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
};
//int child=0;
int perfect(){
	int i;
	for(i=0;i<n&&visited[i]!=-1;i++);
	if(i==n)return -1;
	return i;
}
stack s;
stak s1;
void strongly_connected(int y){
	visited[y]=low[y]=++track;
	int child=0;
	int flag=0;
	for(int i=0;i<n;i++){
		if(visited[i]==-1&&A[y][i]!=0){
			parent[i]=y;
			edge temp;
			temp.a=y;
			temp.b=i;
			s1.push(temp);
			child++;
			strongly_connected(i);
			low[y]=min(low[y],low[i]);
			if(y!=0 && A[y][i]!=0){
			if(low[i]>=visited[y])flag=1;	
			}
			if((y==0 && child>1)||flag==1){
			while(s1.topp().a!=y&&s1.topp().b!=i){
				//cout<<" a "<<y<<" "<<i;
				cout<<s1.topp().a<<"--"<<s1.topp().b<<"  ";
				s1.pop();
			}
			cout<<s1.topp().a<<"--"<<s1.topp().b<<"  ";
			//cout<<" a ";
			s1.pop();
			//cout<<" a ";
			cout<<endl;
			}
		}else if(A[y][i]!=0){
			edge temp;
			temp.a=y;
			temp.b=i;
			s1.push(temp);
			low[y]=min(low[y],visited[i]);
		}
		//5 1 2 2 1 2 3 3 2 3 4 4 3 4 1 1 4 4 5 5 4
				
	}
}
int main(){
	cout<<"Enter the number of vertices ";
	trak=0;
	cin>>n;
	A=new int *[n];
	visited=new int[n];
	low = new int[n];
	parent = new int[n];
	for(int i=0;i<n;i++)A[i]=new int[n];
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		A[i][j]=0;	
	}
	int k,l;
	do{
		cin>>k>>l;
		k--;l--;
		if(k!=-1&&l!=-1)
		A[k][l]=1;
	}while(k!=-1&&l!=-1);
	for(int i=0;i<n;i++){
		cout<<endl;
		for(int j=0;j<n;j++)cout<<A[i][j]<<"  ";
	}
	//1 2 2 3 3 1 1 4 3 4 4 5 3 5 2 6 6 3 7 6 7 8 8 6 8 9 9 10 10 8
	cout<<endl;
	int y=0;
	for(int i=0;i<n;i++){
		visited[i]=low[i]=-1;
		parent[i]=-1;
		
	}
	while(y!=-1){
		
	strongly_connected(y);
	y=perfect();
	while(!s1.isempty()){
		
		cout<<s1.topp().a<<"--"<<s1.topp().b<<"  ";
		s1.pop();
	}
	cout<<endl;
}
	
}
