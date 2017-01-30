#include<bits/stdc++.h>
using namespace std;

int randomize(int arr[], int n){
	srand(time(0));
	
	for(int i=0;i<n;i++){
		arr[i]=i;
	}
	
	for(int i=0;i<n;i++){
		int j = rand()%n;
		int k = rand()%n;
		int temp = arr[j];
		arr[j]=arr[k];
		arr[k]=temp;
	}
}

void print(int arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
}

int main(){
	ofstream ifs("trans.txt");
	int n;
	cin>>n;
	int a[n];
	randomize(a, n);
	srand(time(0));
	//print(a,n);
	for(int i=0;i<n;i++){
		ifs<<"T"<<a[i];
		int num = rand()%4;
		while(num==0)num = rand()%4;
		int small[5]={0};
		while(num>0){
			ifs<<" ";
			int t = rand()%5;
			while(small[t]!=0)t=rand()%5;
			ifs<<"I"<<t;
			small[t]=1;
			num--;
		}
		ifs<<endl;	
	}
	
	ifs.close();
	
	return 0;
}
