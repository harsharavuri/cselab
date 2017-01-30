#include<bits/stdc++.h>
using namespace std;
//int d;
const int max_load=3;
const int max_value=100;
int d=2;
struct bucket{
	int dp;
	int load=-1;
	int a[max_load];
};
bucket *directory[100];
void ALLOCATE(bucket* newbucket){
	newbucket = new(bucket);
}
int H(int key){
	int y=pow(2,d);
	return key%y;
}
char y[100],c=0;
int EXTRACT(int j,int d){
	int a[20];
	int d1=0;
	int y=0;
	while(j>0){
		a[y]=j%2;
		j=j/2;
		y++;
	}
	y--;
	int sum=0;
	while(y>0&&d>0){
		sum = sum + a[y]*pow(2,d1);
		d1++;y--;d--;
	}
	return sum;
}
void READ_DIRECT(int oldbucketbuffer[],int oldbucket,int &load){
	for(int i=0;i<directory[oldbucket]->load;i++){
		oldbucketbuffer[i]=directory[oldbucket]->a[i];
	}
	load=directory[oldbucket]->load;
}
int PUT(int newbucketbuffer[],int recordbuffer[],int& load){
		if(load==max_load)return 0;
		newbucketbuffer[load]=recordbuffer[0];
		load++;
		return 1;
}
void WRITE_DIRECT(int bucketbuffer[],int bucket,int &load){
	for(int i=0;i<load;i++){
		directory[bucket]->a[i]=bucketbuffer[i];
	}
	directory[bucket]->load=load;
}
int GET_NEXT(int oldbucketbuffer[],int recordbuffer[],int load,int& i){
	++i;
	if(i>load)return -1;
	recordbuffer[0]=oldbucketbuffer[i];
	return 1;	
}
void EXPAND(){
	for(int i=d+1;i<=pow(2,d)-1;i++)directory[i]=new(bucket);
	
	for(int i=pow(2,d)-1;i>=0;i--){
		directory[2*i+1]=directory[i];
		directory[2*i]=directory[i];
	}
	d=d+1;
}
int DELETE(int oldbucketbuffer[],int recordbuffer[],int &load){
	int i;
	for(i=0;i<=load;i++)if(oldbucketbuffer[i]==recordbuffer[0])break;
	if(i==load+1)return 0;
	for(int j=i;j<load;j++)oldbucketbuffer[j]=oldbucketbuffer[j+1];
	load--;
	return 1;
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
int iEOF(int bucketbuffer[],int load,int i){
	i++;
	if(i>load)return 0;
	return 1; 
}
void SPLIT(int n,int newbucket){
	//newbucket = ALLOCATE(newbucket);
	//newbucket=n+1;
	int oldbucket=n;
	int load1;
	int oldbucketbuffer[40];
	int newbucketbuffer[40];
	int recordbuffer[40];int i=-1;
	int load;
	READ_DIRECT(oldbucketbuffer,oldbucket,load);
	while(!iEOF(oldbucketbuffer,load,i)){
		GET_NEXT(oldbucketbuffer,recordbuffer,load,i);
		if(EXTRACT(recordbuffer[0],d)%2==1){
			DELETE(oldbucketbuffer,recordbuffer,load);
			PUT(newbucketbuffer,recordbuffer,load1);
			
		}
		i++;
	}
	WRITE_DIRECT(oldbucketbuffer,oldbucket,load);
	WRITE_DIRECT(newbucketbuffer,newbucket,load1);
}
void JOIN(int bucket1,int bucket2, int& dp, bool error){
	int bucketbuffer1[40];int load1;
	int bucketbuffer2[40];int load2;
	READ_DIRECT(bucketbuffer1,bucket1,load1);
	READ_DIRECT(bucketbuffer2,bucket1,load2);
	error=false;
	int recordbuffer[40];
	int i=-1;
	while(!iEOF(bucketbuffer2,load1,i)&&!error){
		GET_NEXT(bucketbuffer2,recordbuffer,load1,i);
		int a = PUT(bucketbuffer1,recordbuffer,load1);
		if(a==0)error=true;
	}
	if(!error){
		WRITE_DIRECT(bucketbuffer1,bucket1,load1);
		directory[bucket2]=directory[bucket1];
		dp=dp-1;
	}
}
void ADD(int recordbuffer[],int dp){
	int h = H(recordbuffer[0]);
	int index=EXTRACT(H(recordbuffer[0]),d);
	int load;
	int bucketbuffer[40];
	READ_DIRECT(bucketbuffer,index,load);
	//int dp=directory[index]->dp;
	int a = PUT(bucketbuffer,recordbuffer,load);
	if(a==0){
		if(dp==d)EXPAND();
		int first = pow(2,d-dp)*EXTRACT(h,dp);
		int last = first + pow(2,d-dp)-1;
		directory[first+(last-first)/2]=new(bucket);
		bucket* newbucket=directory[first+(last-first)/2];
		SPLIT(index,first+(last-first)/2);
		directory[index]->dp++;directory[index+1]->dp++;
		first=first+(last-first)/2;
		for(index = first ;index<=last;index++){
			directory[index]=newbucket;
		}
		ADD(recordbuffer,dp);
	}else{
		WRITE_DIRECT(bucketbuffer,index,load);
	}
}
int TEST(int p,bool& ok){
	ok=true;
	int dp = directory[p]->dp;
	int load1=directory[p]->load;
	int load2=directory[p+1]->load;
	int dp1=directory[p]->dp;
	int dp2=directory[p+1]->dp;
	if((load1+load2)/2 >0.5)ok=false;
	else if(dp1!=dp2)ok=false;
	else if (EXTRACT(p,dp)!=EXTRACT(p+1,dp))ok = false;
}
void DELETE(int key){
	int h=H(key);
	int index= EXTRACT(h,d);
	int dp = directory[index]->dp;
	bucket* buck= new(bucket);buck=directory[index];
	int first=pow(2,d-dp)*EXTRACT(h,dp);
	int last=first+pow(2,d-dp)-1;
	bool ok=false;
	int p=first-1;
	if(p>=0)TEST(p,ok);
	if(!ok&&last<pow(2,d)-1){
		p=last;
		TEST(p,ok);
		p=p+1;
	}
	bool error=false;
	if(ok){
		JOIN(index,p,dp,error);
		if(!error)directory[p]=directory[index];
		CONTRACT();
	}
}

int main(){
	
	
}
