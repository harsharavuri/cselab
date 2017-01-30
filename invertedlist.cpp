#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct student{
	char name[13];
	char roll[4];
	char branch[4];
};
struct keynode{
	char name[13];
	int index;
};
struct secondary{
	char name[13];
	char branch[4];
	
	int index;
};
void pack(student s,char a[]){
	int l;int i=0;
	while(s.roll[i]!='\0')i++;
	while(i<3){
	s.roll[i]='*';i++;}
	s.roll[i]='\0';i=0;
	while(s.name[i]!='\0')i++;
	while(i<12){
		s.name[i]='*';i++;
	}
	s.name[i]='\0';
	i=0;
	while(s.branch[i]!='\0')i++;
	while(i<3){
	s.branch[i]='*';
	}
	s.branch[i]='\0';
	strcpy(a,s.name);
	strcat(a,"|");
	strcat(a,s.roll);
	strcat(a,"|");
	strcat(a,s.branch);
	strcat(a,"#");
	strcat(a,"\0");	
}
student unpack(char a[]){
	int i=0;int j=0;
	student s;
	while(a[i]!='*'&&a[i]!='|'){
		s.name[j]=a[i];i++;j++;
	}

	s.name[j]='\0';
	if(a[i]=='*'){
		while(a[i]!='|')i++;
	}
	s.name[j]='\0';j=0;i++;
		while(a[i]!='|'&&a[i]!='*'){
		s.roll[j]=a[i];i++;j++;
		
	}
	if(a[i]=='*'){
		while(a[i]!='|')i++;
	}
	s.roll[j]='\0';
	j=0;i++;
	while(a[i]!='*'&&a[i]!='\0'){
		s.branch[j]=a[i];i++;j++;
	}
	s.branch[j]='\0';

	return s;
}

void keysort(){
	char a[50];
	fstream inf("key_fixed.txt",ios::in|ios::binary);
	fstream outfi("keynode.txt",ios::in|ios::out|ios::binary);int i=0;
	fstream outf2("secondary.txt",ios::in|ios::out|ios::binary);
	fstream outf3("inverted.txt",ios::in|ios::out|ios::binary);
	while(!inf.eof()){
		inf.getline(a,50,'#');
		i++;
		

	}

	struct keynode keyn[i];
	struct secondary secn[i];
	int n=i;
	n--;inf.close();
	ifstream infi("key_fixed.txt",ios::in|ios::binary);
	
	i=0;
	
	while(!infi.eof()){
		infi.getline(a,50,'#');
		student s=unpack(a);
	
		keyn[i].index=i;
		strcpy(secn[i].name,s.name);
		strcpy(keyn[i].name,s.name);
		strcpy(secn[i].branch,s.branch);
		secn[i].index=i;
		
		i++;
		
	}

	
	for(int i=0;i<n;i++){
		int k=0;
		
		while(secn[i].name[k]!='\0')k++;
		
		while(k<12){
		secn[i].name[k]='*';k++;
		
		}
	
		secn[i].name[k]='\0';
		
		outf3<<secn[i].index<<"**|"<<secn[i].name<<"|";
		outf3<<"***#";
	}
	
	keynode buff;

	int j=0;
	for(i=0;i<n;i++){
		
		for(int j=i+1;j<n;j++){
			if(strcmp(keyn[j].name,keyn[i].name)==1){
				buff=keyn[i];
				keyn[i]=keyn[j];
				keyn[j]=buff;
			}
		}
	}
	j=0;
	secondary sec;
	for(i=0;i<n;i++){
		
		for(int j=i+1;j<n;j++){
			if(strcmp(secn[j].branch,secn[i].branch)==1){
				sec=secn[i];
				secn[i]=secn[j];
				secn[j]=sec;
			}
		}
	}
	cout<<" n "<<n;char c[30];
	outf3.close();int flag = 0;
	fstream outf4("invertedfile.txt",ios::in|ios::out|ios::binary);
	for(int i=0;i<n;i++){
		if(i==0)
		{	int count=0;
			outf2<<secn[i].branch;
			while(!outf4.eof()&&flag==0){
				int k=0;
				char buffer[10];
				outf4.getline(c,30,'#');
				while(c[k]!='|')k++;
				k++;int l=0;
				while(c[k]!='|'){
				buffer[l]=c[k];
				k++;l++;
				
				}
				buffer[l]='\0';
				if(strcmp(buffer,secn[i].name))flag=1;
				else
				count++;
			}	
			if(flag==1){
				
				outf2<<"|"<<count<<"**#";
		
		}else{
			if(strcmp(secn[i].branch,secn[i-1].branch)==0){
				int count=0;
				outf2.seekg((i+1)*8-4);int m=0;
				char ch[2];outf2.get(ch[m]);
				while(ch[0]!='*'){
					
					outf2.get(ch[0]);
					
					
				}
				ch[0]='\0';
				
				outf4.seekp((atoi(ch)+1)*17-4,ios::beg);
				
			while(!outf4.eof()&&flag==0){
				int k=0;
				char buffer[10];
				outf4.getline(c,30,'#');
				while(c[k]!='|')k++;
				k++;int l=0;
				while(c[k]!='|'){
				buffer[l]=c[k];
				k++;l++;
				
				}
				buffer[l]='\0';
				if(strcmp(buffer,secn[i].name))flag=1;
				else
				count++;
				}
			}else{
				fstream outf4("invertedfile.txt",ios::in|ios::out|ios::binary);
				for(int i=0;i<n;i++){
				if(i==0)
				{	int count=0;
			outf2<<secn[i].branch;
			while(!outf4.eof()&&flag==0){
				int k=0;
				char buffer[10];
				outf4.getline(c,30,'#');
				while(c[k]!='|')k++;
				k++;int l=0;
				while(c[k]!='|'){
				buffer[l]=c[k];
				k++;l++;
				
				}
				buffer[l]='\0';
				if(strcmp(buffer,secn[i].name))flag=1;
				else
				count++;
			}	
			if(flag==1){
				
				outf2<<"|"<<count<<"**#";
	
			}
		}
	}
	
	

	for(int i=0;i<n;i++){
		
		int k=0;
		while(keyn[i].name[k]!='\0')k++;
		while(k<12){
		keyn[i].name[k]='*';k++;
		}
		keyn[i].name[k]='\0';
		int z=2;
		char ch;
		
		
		outfi<<keyn[i].name<<"|"<<keyn[i].index;
		
		if(keyn[i].index<10)outfi<<"*";
		outfi<<"#";	
	
	}
	
}
}
}
}
}
char check[30];
int binary_search(ifstream & inf,int l,int h ){
	if(h<l)return 0;
	
	if(h>l){
		int mid=(l+h)/2;
		inf.seekg((mid-1)*16);
		char a[30];
		inf.getline(a,30,'#');
		char c[30];
		int b=0;
		while(a[b]!='*'&&a[b]!='#'&&a[b]!='\0'){
			c[b]=a[b];b++;
		}
		c[b]='\0';
		if(strcmp(check,c)==0)return 1;
		else{
			if(strcmp(c,check)==-1)return binary_search(inf,l,mid-1);
			else
			return binary_search(inf,mid+1,h);
		}
	}else if(h==l){
		inf.seekg((l-1)*16);
		char a[30];
		inf.getline(a,30,'#');
		char c[30];
		int b=0;
		while(a[b]!='*'&&a[b]!='#'&&a[b]!='\0'){
			c[b]=a[b];b++;
		}
		c[b]='\0';
		if(strcmp(check,c)==0){
		cout<<"Found ";
		return 1;
		}
		else return 0;
	}

}

int main(){
	ofstream outf("key_fixed.txt");
	char a[40];
	cout<<"Enter the number of records ";
	int n;student s;
	cin>>n;
	cout<<" Enter the name, roll and branch of the student ";
	for(int i=0;i<n;i++){
		cin>>s.name>>s.roll>>s.branch;
		pack(s,a);
	
		outf<<a;
	}
	outf.close();
	keysort();
	ifstream inf("keynode.txt");
	cout<<"Enter the name to be checked ";
	cin>>check;
	int b=binary_search(inf,1,n);
	if(b)cout<<"Found ";
}


