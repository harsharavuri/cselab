
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
	ifstream inf("key_fixed.txt",ios::in|ios::binary);
	ofstream outfi("keynode.txt");int i=0;
	ofstream outf2("secondary.txt");
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
	cout<<" n "<<n;
	outf3.close();
	fstream outf4("inverted.txt",ios::in|ios::out|ios::binary);
	
	cout<<secn[0].branch<<secn[1].branch<<secn[2].branch;
	for(int i=0;i<n;i++){
		int leng=0;
		if(i==0)
		{		
				while(secn[i].name[leng]!='\0')leng++;
				while(leng<12){
				secn[i].name[leng]='*';leng++;
		}
		secn[i].name[leng]='\0';
			outf2<<secn[i].branch<<"|"<<secn[i].name;
			
		}else{
			if(strcmp(secn[i].branch,secn[i-1].branch)==0){
				outf2<<"|"<<secn[i].name;
						
			
			}else{
				outf2<<"#"<<secn[i].branch<<"|"<<secn[i].name;
			}
		}
	}
	outf2<<"#";
	

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
int secondarycheck(char y[],char z[]){
	ifstream inf("secondary.txt");
	inf.seekg(0);
	int flag=0;
	while(!inf.eof()&&flag==0){

		inf.getline(z,40,'#');
		char str[10];
		str[0]=z[0];str[1]=z[1];str[2]=z[2];
		str[3]='\0';
		if(strcmp(str,y)==0){
			flag=1;
			return flag;
		}
	
		if(inf.eof())return 0;
		
	}
	 return 0;
	if(inf.eof())cout<<"Not found";
}
int main(){
	ofstream outf("key_fixed.txt");
	char a[40];
	cout<<" Enter the number of records ";
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
	char y[20];
	ifstream inf("keynode.txt");
	cout<<"Enter the branch to be checked";
	cin>>y;
	char z[40];
	int chm= secondarycheck(y,z);
	if(chm==0){
		cout<<"Not Found";
		return 0;
	}

	int m=0;

	while(z[m]!='|')m++;
	m++;
	int v=0;
	
	cout<<"z "<<z;

	while(z[m]!='\0'){
	v=0;
	while(z[m]!='|'&&z[m]!='*'){
	check[v]=z[m];v++;m++;
	}
	if(z[m]=='*')
	while(z[m]!='|'&&z[m]!='\0')m++;
	m++;
	check[v]='\0';

	int b=binary_search(inf,1,n);
	
	if(b)cout<<check<<"  ";
	}
}


