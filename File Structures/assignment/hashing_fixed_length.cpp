#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct student{
char index[3];
char roll[3];
};
int hash(int key,int size){
	return key%size;
}
void create(ofstream & outf,int size){
	for(int i=0;i<size;i++){
		outf<<i;char ch[10]="-1";
		if(i<10)outf<<"*";
		outf<<"|"<<ch<<"#";
	}
}
void pack(student s, char a[]){
	int i=0;
	//s.roll[i]='#';
	strcpy(a,s.index);strcat(a,"|");strcat(a,s.roll);strcat(a,"#");
}
student unpack(char a[]){
	int i=0;int j=0;
	student s;
	while(a[i]!='*'&&a[i]!='#'){
		s.index[j]=a[i];i++;j++;
	}
	i++;
	if(a[i]=='*'){
		while(a[i]!='|')i++;
	}
	s.index[j]='\0';j=0;i++;
		while(a[i]!='\0'&&a[i]!='*'){
		s.roll[j]=a[i];i++;j++;
		//cout<<"  "<<a[i]<<"  ";
	}
	
	s.roll[j]='\0';
	//cout<<atoi(s.roll);
	return s;
}
void insert(fstream & foutin,int size ){
	student s1,s2;char a[10];
	int key,j,i,k;i=0;
	j=0;int n;
	do{
		cout<<"Enter the roll no ";
		cin>>s1.roll;
		//strcpy(s1.index,"0");
		char ch;
		int n=atoi(s1.roll);
	
		//if(n==-1){
		//	return;
		//}
		key=hash(n,size);
		char b[10];
		foutin.seekp(key*6,ios::beg);
		foutin.getline(b,10,'#');
		//foutin>>ch;
		//cout<<b<<endl;
		s2=unpack(b);
		cout<<atoi(s2.roll);
		if(atoi(s2.roll)==-1){
			strcpy(s1.index,s2.index);
			pack(s1,a);
			foutin.seekp(key*6,ios::beg);
			foutin<<a;
		}else{j=key;
			j=(j+1)%size;foutin.getline(b,10,'#');s2=unpack(b);
		while(j!=key&&atoi(s2.roll)!=-1){
		j=(j+1)%size;foutin.seekp(j*6,ios::beg);
		foutin.getline(b,10,'#');s2=unpack(b);
		}
		if(atoi(s2.roll)==-1){
			strcpy(s1.index,s2.index);
			pack(s1,a);
			foutin.seekp(j*6,ios::beg);
			foutin<<a;
		}
		}
		i++;//cout<<i;
		if(i==size){
			cout<<"size limit reached ";return;
		}
	}while(i!=size);
}
int main(){
	student s;
	ofstream outf("newhash.txt");
	cout<<"Enter the size of the hash table ";
	int size;
	cin>>size;
	create(outf,size);	
	outf.close();
	fstream fin("newhash.txt",ios::binary|ios::in|ios::out);
	//cout<<sizeof(student);
	insert(fin,size);
}
