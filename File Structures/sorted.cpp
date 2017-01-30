#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream inf("smap.txt");
	int z=1;
	int i,j,l;
	cout<<"Enter the number of elements \n";
	
  	int n=14;
	inf>>i;inf>>j;
	if(i<j){
		cout<<i<<" ";
	}
	else{
		cout<<j<<" ";
		int temp=j;
		j=i;
		i=temp;
	}
	inf>>l;
	while(z<n){
		if(l<j&&l>i&&z<n){
			cout<<l<<" ";
			i=l;
			inf>>l;z++;
		}
		else if(l>j&&z<n){
			cout<<j<<" ";
			i=j;
			j=l;
			inf>>l;z++;
		}
		else if(z<n){
			cout<<j<<endl;
			i=l;
			inf>>j;z++;
			if(i<j&&z<n){
		cout<<i<<" ";
	}
	else if(z<n){
		cout<<j<<" ";
		int temp=j;
		j=i;
		i=temp;
	}
	inf>>l;z++;
		}
		
	}
}
