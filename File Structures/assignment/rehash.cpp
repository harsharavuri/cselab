#include<iostream>
#include<fstream>
using namespace std;
int hash(int key,int size){
	return key%size;
}
void create(ofstream & fout,int size){
	int k=-1;
	for(int i=0;i<size;i++){
		fout<<k<<"\n";
	}
}
void insert(fstream & foutin,int size){
	int key,j,i,k;i=0;
	j=0;int n;
	do{
		cout<<"Enter the roll no ";
		cin>>n;
		if(n==-1){
			return;
		}
		key=hash(n,size);
			foutin.seekp(key*sizeof(int),ios::beg);
		foutin>>k;
		if(k==-1){
			foutin.seekp(key*sizeof(int),ios::beg);
			foutin<<n<<" ";
		}else{j=key;int l=1;
			j=(j+l*((key%7)+1))%size;foutin>>k;
		while(i!=key&&k!=-1){
		j=(j+l*((key%7)+1))%size;foutin.seekp(j*sizeof(int),ios::beg);
		foutin>>k;l++;
		}
		if(k==-1){
			foutin.seekp(j*sizeof(int),ios::beg);
			foutin<<n<<" ";
		}
		}
		i++;cout<<i;
		if(i==size){
			cout<<"size limit reached ";return;
		}
	}while(i!=size);
}
int main(){
	ofstream outf("buffer.txt");
	int size;
	cout<<"Enter the size of the hash table ";
	cin>>size;
	create(outf,size);
	outf.close();
	fstream foutin("buffer.txt",ios::binary|ios::out|ios::in);
	insert(foutin,size);int k;int i=0;
	foutin.close();
	ofstream fout("linear.txt");
	ifstream fin("buffer.txt");
	for(int i=0;i<size;i++){
		fin>>k;
		fout<<i<<" "<<k<<"\n";
	}
	
}
