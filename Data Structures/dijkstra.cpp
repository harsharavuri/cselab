#include<iostream>
using namespace std;
int main(){
	cout<<"Enter the number of vertices ";
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	a[i][j]=0;
	int dist[n];
	for(int i=0;i<n;i++)dist[i]=1000;
	int max=1000;
	int pv[n];
	for(int i=0;i<n;i++)pv[i]=-1;
	int d;
	cout<<" Enter the destination vertex ";
	cin>>d;
	d--;
	//int b[]={1 ,2 ,2 ,1 ,4 ,1 ,2 ,4 ,3 ,2 ,5 ,10 ,3 ,1 ,4 ,3 ,6 ,5 ,4 ,3 ,2 ,4 ,6 ,8 ,4 ,7 ,4 ,4 ,5 ,2, 5, 7 ,6 ,7, 6, 1};
	int visit[n];
	for(int i=0;i<n;i++)visit[i]=0;
	int i,j,c,s;
	s=0;c=0;
	do{
		cin>>i>>j;
		i--;j--;
		int weight;
		cin>>weight;
		if(i!=-1&&j!=-1&&i<n&&j<n){
			a[i][j]=weight;
		}
	}while(i>=0&&j>=0&&i<=n&&j<=n);
	for(int i=0;i<n;i++){
	cout<<endl<<i<<"  ";
	for(int j=0;j<n;j++)
	cout<<a[i][j]<<"  ";
	}
	visit[0]=1;
	int count=0;
	int track[n];
	for(int i=0;i<n;i++)
	{
		c=i;
			while(c!=d){
				visit[c]=1;
			for(int y=0;y<n;y++){
				if(/*visit[y]!=1&&*/a[c][y]!=0){
					if((dist[y]>dist[c]+a[c][y])||dist[y]==max){
						dist[y]=dist[c]+a[c][y];
						if(dist[c]==max)dist[y]=dist[y]-max;
						pv[y]=c;
					}
					if(visit[y]!=1)
					track[count++]=y;
				}
			}
			if(count>0)c=track[--count];
	 }
		
	}
	//1 2 2 1 4 1 2 4 3 2 5 10 3 1 4 3 6 5 4 3 2 4 6 8 4 7 4 4 5 2 5 7 6 7 6 1
	int m=pv[d];
	int sum=a[m][d];
	cout<<m<<"  ";
	int prev=m;
	while(m!=s){
		m=pv[m];
		cout<<m+1<<"  ";
		sum=sum+a[m][prev];
		prev=m;
	}
	cout<<dist[d]<<"  "<<sum;
}
