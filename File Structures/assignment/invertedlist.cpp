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
int search_inv(fstream & outf4,char name[],int place){
	char s[40];
	int start=0;
	char gt[3];
	char extract[30];
	//place=place;
	place=place%3;
	outf4.seekg(place*21,ios::beg);
	while(!outf4.eof()){
		//outf4.getline(s,40,'#');
		outf4.seekp(start*20,ios::beg);
		outf4.getline(s,40,'|');
		outf4.getline(s,40,'|');
		//cout<<name<<" name "<<s<<" ss ";
		if(strcmp(s,name)==0){
		outf4.seekp(start*21);
		outf4.get(gt[0]);
		gt[1]='\0';
		//cout<<" Stop ";
		return atoi(gt);
		}
		
		start++;
	}
	return -1;
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
		//cout<<" a "<<a;

	}
	//cout<<" i "<<i;
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
	//	cout<<"     secn[i].name   "<<secn[i].name<<"  s.name  "<<s.name<<"  keyn[i].name "<<keyn[i].name<<"  index  "<<secn[i].branch<<"\n";
		
		i++;
		//cout<<" i "<<i;
		//cout<<" s.name "<<s.name<<" s.index "<<i;
	}
	//char buff[40];
	
	for(int i=0;i<n;i++){
		int k=0;
		
		while(secn[i].name[k]!='\0')k++;
		//cout<<" i "<<k;
		while(k<12){
		secn[i].name[k]='*';k++;
		//cout<<" i ";
		}
		//cout<<"     secn[i].name   "<<secn[i].name;
		secn[i].name[k]='\0';
		//cout<<" sec  "<<secn[i].name;
		outf3<<secn[i].index<<"**|"<<secn[i].name<<"|";
		outf3<<"***#";
	}
	
	keynode buff;

	int j=0;
	for(i=0;i<n;i++){
		//strcpy(buff,keyn[i].name);
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
		//strcpy(buff,keyn[i].name);
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
	int buffer;char sr[3];
	char ch;
	fstream outf4("inverted.txt",ios::in|ios::out|ios::binary);
	for(int i=0;i<n;i++){
		if(i==0)
		{	cout<<" Fourth ";
			outf2<<secn[i].branch<<"|"<<secn[i].index<<"**#";
			buffer=secn[i].index+1;
		}else{
			
			if(strcmp(secn[i].branch,secn[i-1].branch)==0){
				outf4.seekg(buffer*21-4,ios::beg);
				outf4.get(ch);
					//cout<<" Third ";
				while(ch!='*'){
					sr[0]=ch;
					sr[1]='\0';
				
					buffer=atoi(sr)+1;
					outf4.get(ch);
					outf4.seekg(buffer*21-4,ios::beg);
				}
				
				int cas = search_inv(outf4,secn[i].name,buffer);	
				if(cas==-1){
					//cout<<"Not Found ";
					return;
				}
				//buffer=buffer+1;
				//buffer=buffer%3;
				outf4.seekg(buffer*21-4,ios::beg);
				char mco[3];
				itoa(cas,mco,10);	
				outf4<<mco;
				cout<<" First ";
				//cout<<secn[i].branch<<secn[i-1].branch;	
			}else{
				cout<<" Second ";
				outf2<<secn[i].branch<<"|"<<secn[i].index<<"**#";
				buffer=secn[i].index+1;
			}
		}
	}
	
	
//	for(int y=0;y<n;y++){
//		cout<<keyn[y].name<<" ";
//	}
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
		//cout<<" "<<keyn[i].name;
		outfi<<keyn[i].name<<"|"<<keyn[i].index;
		/*keyn[i].index=keyn[i].index*10;
		while(keyn[i].index<1000)
		{
		outfi<<"*";
		keyn[i].index=keyn[i].index*10;}*/
		//cout<<" i ";
		if(keyn[i].index<10)outfi<<"*";
		outfi<<"#";	
		//i++;
	}

}
char check[30];
int binary_search(ifstream & inf,int l,int h ){
	if(h<l)return 0;
	//ifstream infi("key_fixed.txt",ios::in|ios::binary);
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
	cout<<" Enter the number of records ";
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
	int b=binary_search(inf,1,n);
	if(b)cout<<"Found ";
}


