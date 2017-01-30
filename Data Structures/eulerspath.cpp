#include<iostream>
using namespace std;
int *degree;
int n;
//const int l;
int check(){
	int i;
	for(i=0;i<n&&degree[i]==0;i++);
	if(i==n)return 0;
	return 1;
}	
int get(int **a,int i){
	for(int j=0;j<n;j++){
		if(a[i][j]!=0)return j;
	}
	return 0;
}
int main(){
	
	cout<<"Enter the number of vertices ";
	cin>>n;
	//l=n;
	degree=new int(n);
	for(int y=0;y<n;y++)degree[y]=0;
	int a[n][n];int i,j;
	cout<<"Enter the elements of the graphs ";
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)a[i][j]=0;
	do{
		cin>>i>>j;
		i--;j--;
		if(i!=-1&&j!=-1){
		a[i][j]=1;
		a[j][i]=1;
		degree[i]++;degree[j]++;
		//cout<<i<<"  "<<j<<"  "<<endl;
		}
	}while(i!=-1&&j!=-1);
	int buffer[20];int b=0;
	int splice[40];int s=0;
	//int i;
	for(i=0;i<n&&degree[i]%2!=1;i++)cout<<degree[i]<<"   ";
	int k=i;
	//i=1;
	//cout<<k<<"  a  "<<endl;
	buffer[b++]=i;int track;
	for(int i=0;i<n;i++){cout<<endl;
	for(int j=0;j<n;j++)cout<<a[i][j]<<"  ";
	
	}
	//cout<<i<<"  ";
	cout<<endl;
	int y;
	//cout<<check()<<"  ";
	// 1 2 2 3 3 4 4 1 1 5 4 5
	while(check()){
		int j;
		//cout<<" a ";
		for(j=0;j<n;j++){
		if(a[i][j]!=0)break;
		}
		if(j<n){
			degree[i]=degree[i]-1;degree[j]=degree[j]-1;a[i][j]=0;a[j][i]=0;
			cout<<i<<"  "<<degree[i]<<"  ";
			buffer[b++]=j;
			i=j;
			//cout<<i<<"  ";//<<j<<"  ";
			//cout<<" a ";
		}else{
			//cout<<" a ";
			buffer[b++]=i;
			if(check()){
				for(y=0;y<b;y++){
					if(degree[buffer[y]]!=0){
						//track=y;
						i=buffer[y];
						if(s==0){
							//cout<<" bba ";
							for(int y=0;y<b;y++){
							splice[y]=buffer[y];
							}
							s=b;
							b=0;
							track=b;
						}else{
							//cout<<" b  a ";
							int final[100];int cv;
							for(cv=0;cv<track;cv++)final[cv]=splice[cv];
							for(int j=0;j<b;j++){
								final[cv]=buffer[b];cv++;
							}
							for(int j=track;j<s;j++){
							final[cv]=splice[j];
							cv++;
							}
							track=y+track;
							for(int k=0;k<cv;k++)splice[cv]=final[cv];
							s=cv;
						}
						break;
					}
				}
			}
		}
	}
	/*if(s!=0){
		int final[100];int cv;
							for(cv=0;cv<track;cv++)final[cv]=splice[cv];
							for(int j=0;j<b;j++){
								final[cv]=buffer[b];cv++;
							}
							for(int j=track;j<s;j++){
							final[cv]=splice[j];
							cv++;
							}
							track=y+track;
							for(int k=0;k<cv;k++)splice[cv]=final[cv];
							s=cv;
	}*/
	// 1 2 2 3 3 4 4 1 1 5 5 3 2 5 5 4 1 6 6 4
	//cout<<" a a ";
	//cout<<b<<"  a   a  ";
	for(int i=0;i<s;i++)cout<<splice[i]<<" a ";
	//for(int i=0;i<b;i++)cout<<buffer[i]<<" a ";
}
