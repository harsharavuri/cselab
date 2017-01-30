#include<iostream>
using namespace std;
int d;
const int max_load=3;
const int max_value=100;
int d=2;
struct bucket{
	int dp;
	int load=0;
	int a[max_load];
};
bucket *directory[100];
void ALLOCATE(bucket* newbucket){
	newbucket = new(bucket);
}
int H(int key){
	return key%8;
}
char y[100],c=0;
int extract(int j,int d){
	int da=j%2;
	y[c++]=da;
	if(j>0)return extract(j/2);
	y[c]='\0';
	//char *l;
	strrev(y);
	if(c<d)return atoi(y);
	else{
		y[d]='\0';
		return atoi(y);
	}
}
void EXPAND(){
	for(int i=d+1;i<=pow(2,d)-1;i++)directory[i]=new(bucket);
	
	for(int i=pow(2,d)-1;i>=0;i--){
		directory[2*i+1]=directory[i];
		directory[2*i]=directory[i];
	}
	d=d+1;
}
void CONTRACT(){
	int i=0;
	bool error=false;
	while(i<pow(2,d)&&!error){
		if(directory[i]!=directory[i+1])error=true;
		i=i+2;
	}
	if(!error){
		d=d-1;
		for(int i=0;i<2*d-1;i++)directory[i]=directory[2*i+1];
	}
}
void SPLIT(int o,int n){
	bucket[n] = ALLOCATE(bucket[n]);
}
int main(){
	
	
}
