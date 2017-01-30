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
	//i++;
	s.name[j]='\0';
	if(a[i]=='*'){
		while(a[i]!='|')i++;
	}
	s.name[j]='\0';j=0;i++;
		while(a[i]!='|'&&a[i]!='*'){
		s.roll[j]=a[i];i++;j++;
		//cout<<"  "<<a[i]<<"  ";
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
	//cout<<atoi(s.roll);
	return s;
}

void keysort(){
	char a[50];
	ifstream inf("key_fixed.txt",ios::in|ios::binary);
	ofstream outfi("keynode.txt");int i=0;
	while(!inf.eof()){
		inf.getline(a,50,'#');
		i++;
		//cout<<" a "<<a;

	}
	//cout<<" i "<<i;
	keynode keyn[i];
	int n=i;
	n--;inf.close();
	ifstream infi("key_fixed.txt",ios::in|ios::binary);;i=0;
	while(!infi.eof()){
		infi.getline(a,50,'#');
		student s=unpack(a);
		strcpy(keyn[i].name,s.name);
		keyn[i].index=i;i++;
				//cout<<" i "<<i;
		//cout<<" s.name "<<s.name<<" s.index "<<i;
	}
	//char buff[40];
	keynode buff;
	
	int j=0;
	for(i=0;i<n;i++){
		//strcpy(buff,keyn[i].name);
		for(int j=i+1;j<n;j++){
			if(strcmp(keyn[i].name,keyn[j].name)==1){
				buff=keyn[i];
				keyn[i]=keyn[j];
				keyn[j]=buff;
			}
		}
	}
	//cout<<" "<<keyn[0].name<<" ";
	for(int i=0;i<n;i++){
		//cout<<keyn[i].name<<" "<<keyn[i].index<<"\n";
		int k=0;
		while(keyn[i].name[k]!='\0')k++;
		while(k<12){
		keyn[i].name[k]='*';k++;
		}
		keyn[i].name[k]='\0';
		int z=2;
		char ch;
		
		//cout<<" "<<(char*)z;
		outfi<<keyn[i].name<<"|"<<keyn[i].index;
		/*keyn[i].index=keyn[i].index*10;
		while(keyn[i].index<1000)
		{
		outfi<<"*";
		keyn[i].index=keyn[i].index*10;}*/
		if(keyn[i].index<10)outfi<<"*";
		outfi<<"#";	
	}
	
}
char check[30];
int binary_search(ifstream & inf,int l,int h ){
	if(h<l)return 0;
	ifstream infi("key_fixed.txt",ios::in|ios::binary);
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
		if(strcmp(check,c)==0){
		if(a[b]=='*'){
			while(a[b]!='|')b++;
		}
		b++;int za=0;
		while(a[b]!='*'&&a[b]!='#'){
			c[za]=a[b];b++;za++;
		}
		c[za]='\0';
		infi.seekg((atoi(c))*21);
		infi.getline(c,30,'#');
		student s=unpack(c);
		cout<<"  "<<s.name<<" "<<s.roll<<" "<<s.branch;
		return 1;
		
		}
		else{
			if(strcmp(c,check)==1)return binary_search(inf,l,mid-1);
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
		if(a[b]=='*'){
			while(a[b]!='|')b++;
		}
		b++;int za=0;
		while(a[b]!='*'&&a[b]!='#'){
			c[za]=a[b];b++;za++;
		}
		c[za]='\0';
		infi.seekg((atoi(c))*21);
		infi.getline(c,30,'#');
		student s=unpack(c);
		cout<<"  "<<s.name<<" "<<s.roll<<" "<<s.branch;
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
		//cout<<a;
		outf<<a;
	}
	outf.close();
	keysort();
	ifstream inf("keynode.txt");
	cout<<"Enter the name to be checked ";
	cin>>check;
	binary_search(inf,1,n);
	if(binary_search)cout<<" Found ";
	else
	cout<<"Not Found ";
}


