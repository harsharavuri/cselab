#include<iostream>
using namespace std;
int **A,n,trak=0;
int *visited,*low,*present;
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
int child=0;
int perfect(){
	int i;
	for(i=0;i<n&&visited[i]!=-1;i++);
	if(i==n)return -1;
	return i;
}
stack s;
void strongly_connected(int y){
	visited[y]=low[y]=++track;
	int flag=0;
	for(int i=0;i<n;i++){
		if(visited[i]==-1&&A[y][i]!=0){
			strongly_connected(i);
			if(y==0)child++;
			low[y]=min(low[y],low[i]);
		}else if(A[y][i]!=0){
			low[y]=min(low[y],visited[i]);
		}
			if(y!=0 && A[y][i]!=0){
			if(low[i]>=visited[y])flag=1;	
			}
		}
		if(y==0){
			
			if(child>1)cout<<0<<"  ";
			}
		
	if(flag==1)cout<<y<<"  ";	
	
}
int main(){
	cout<<"Enter the number of vertices ";
	trak=0;
	cin>>n;
	A=new int *[n];
	visited=new int[n];
	low = new int[n];
	present = new int[n];
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
		present[i]=0;
	}
	cout<<"Artculation points are: ";
	while(y!=-1){
	strongly_connected(y);
	y=perfect();
//	cout<<endl;
	}
	/*cout<<" Articulation Points are ";int count=0;int v=0,m=0;
	for(int i=0;i<n;i++)if(A[0][i]!=0){
	if(v==0)v=i;
	else
	m=i;
	count++;
	}
	if(count==2&&A[v][m]==0&&A[m][v]==0)cout<<0<<"  ";
	for(int i=1;i<n;i++){
		int flag=0;int j;
		for(j=i+1;j<n;j++){
			if(A[i][j]!=0){
				flag=1;
				if(low[j]<visited[i])break;
			}
		}
		if(j==n&&flag==1)cout<<i<<"  ";
	}*/
}
