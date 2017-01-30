#include<iostream>
using namespace std;
int *a;
void initialise(int size){
	for(int k=0;k<size;k++)
	{
	a[k]=-1;
	}
}
int find(int i){
	if(a[i]==-1)return i;
	a[i]=find(a[i]);
}
void union_disjoint(int i,int j){
	if(a[j]==-1){
		a[j]=i;
		//a[i]--;
	}
	else if(a[i]==-1){
		a[i]=j;
		//a[j]--;
	}else{
		//cout<<" c ";//cout<<a[i]<<" ";
			union_disjoint(find(a[j]),find(a[i]));
		}
		//cout<<" c ";
}
int reached(int n){
	int i=0;int check=a[i];
	//if(a[i]<0)return 1;
	for(int j=0;j<n;j++){
	if(a[j]<0)i++;
	}
	if(i==1)return 0;
	return 1;
}
int main(){
	cout<<"Enter the number of vertices ";
	int n;
	cin>>n;
	a=new int[n];
	initialise(n);
	int g[n][n];int b[n][n];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
	g[i][j]=0;b[i][j]=0;
	}
	cout<<" Enter the edge vertices and the corresponding weight ";
	//int b[]={1 ,2 ,2 ,1 ,4 ,1 ,2 ,4 ,3 ,2 ,5 ,10 ,3 ,1 ,4 ,3 ,6 ,5 ,4 ,3 ,2 ,4 ,6 ,8 ,4 ,7 ,4 ,4 ,5 ,2, 5, 7 ,6 ,7, 6, 1};
	int i,j,c,s;
	do{
		cin>>i>>j;
		i--;j--;
		int weight;
		cin>>weight;
		if(i!=-1&&j!=-1&&i<n&&j<n){
			g[i][j]=weight;
			b[i][j]=g[i][j]=weight;
		}
	}while(i>=0&&j>=0&&i<=n&&j<=n);
	for(int i=0;i<n;i++){
	cout<<endl<<i<<"  ";
	for(int j=0;j<n;j++)
	cout<<g[i][j]<<"  ";
	}
	int m,l;
	//for(int i=0;i<n;i++)
	//for(int j=0;j<n;j++){
		
	//}
	//1 2 2 1 4 1 2 4 3 2 5 10 3 1 4 3 6 5 4 3 2 4 6 8 4 7 4 4 5 2 5 7 6 7 6 1
	while(reached(n)){
		int min=0;
		//cout<<" b ";
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		if(g[i][j]!=0&&((find(i)!=find(j))||(find(i)<0&&find(j)<0))){
			//cout<<" b ";
			if(min==0){
			//cout<<" a ";
			//union_disjoint(i,j);
			min=g[i][j];
			m=i;l=j;
			}
			else if(g[i][j]<min){
				//cout<<min<<" ";
				min=g[i][j];
				m=i;l=j;
				//union_disjoint(i,j);
			}
			//cout<<" c ";
		}
		//cout<<" a ";
		union_disjoint(m,l);
		//cout<<" a ";
		g[m][l]=0;
		g[l][m]=0;
		cout<<m<<" "<<l<<" ";
	}
}
