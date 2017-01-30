#include<iostream>
#include<string.h>
using namespace std;
void sort(int a[],int y,int k){
	for(int i=y;i<=k;i++){
		for(int j=i;j<=k;j++){
			if(a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main(){
	for(int i=0;i<10;i++){
		if(i==3)continue;
		cout<<i;
	}
}
