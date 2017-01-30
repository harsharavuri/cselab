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
		a[i]--;
	}
	else if(a[i]==-1){
		a[i]=j;
		a[j]--;
	}else{
		if(a[find(a[i])]<a[find(a[j])]){
			int temp=a[find(a[j])];
			union_disjoint(find(a[i]),find(a[j]));
			a[find(a[i])]=a[find(a[i])]-temp+1;
		}
		else{
			int temp=a[find(a[i])];
			union_disjoint(find(a[j]),find(a[i]));
			a[find(a[j])]=a[find(a[j])]-temp+1;
		}
	}
}
int main(){
	int size;
	cout<<"Enter the size of the set ";
	cin>>size;
	a=new int[size];
	initialise(size);
	int a1,b;
	do{
		cin>>a1>>b;
		if(a1!=1&&b!=1)
		union_disjoint(a1,b);
	}while(a1!=-1&&b!=-1);
}
