#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int hash(int key,int size){
	return key%size;
}
void create(ofstream & fout,int size){
	int k=-1;
	for(int i=0;i<size;i++){
		fout<<i<<" "<<k<<"\n";
	}
}
void insert(fstream & foutin,int size){
	int key,j,i,k;i=0;
	j=0;int n;
	do{
		cout<<"Enter the roll no ";
		cin>>n;
		key=hash(n,size);
		foutin.seekp(key*2*sizeof(int)+sizeof(int),ios::beg);
		foutin>>k;
		if(k==-1){
			foutin.seekp(key*2*sizeof(int)+sizeof(int),ios::beg);
			foutin<<n<<'\0';
		}else{j=key;
			key=(key+1)%size;
		while(j!=key&&k!=n){
		key=(key+1)%size;foutin.seekp(key*2*sizeof(int)+sizeof(int),ios::beg);
		foutin>>k;
		}
		if(k==n){
			foutin.seekp(key*2*sizeof(int)+sizeof(int),ios::beg);
			foutin<<n<<'\0';
		}
		}
		i++;
		if(i==size){
			cout<<"size limit reached ";return;
		}
	}while(i!=size);
}
int main(){
	ofstream outf("linearhash.txt");
	int size;
	cout<<"Enter the size of the hash table ";
	cin>>size;
	create(outf,size);
	outf.close();
	fstream foutin("linearhash.txt",ios::binary|ios::out|ios::in);
	insert(foutin,size);
}
