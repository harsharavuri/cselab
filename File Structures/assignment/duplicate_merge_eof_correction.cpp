#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
struct student{
	char name[10];
	char roll[10];
	char marks[5];
};
void pack(student s, char a[]){
	strcpy(a,s.roll);
	strcat(a,"|");
	strcat(a,s.name);
	strcat(a,"|");
	strcat(a,s.marks);
	strcat(a,"#");
	strcat(a,"\0");
}
student unpack(char a[]){
	int i=0;int j=0;
	student s;
	while(a[i]!='|'){
		s.roll[j]=a[i];i++;j++;
	}
	s.roll[j]='\0';j=0;i++;
		while(a[i]!='|'){
		s.name[j]=a[i];i++;j++;
	}
	s.name[j]='\0';j=0;i++;
		while(a[i]!='\0'){
		s.marks[j]=a[i];i++;j++;
	}
	s.marks[j]='\0';
	return s;
}
int main(){
	ifstream inf("first.txt");
	ifstream infile("second.txt");
	student s1;student s2;
	ofstream outf("output.txt");
	char ch[100];char a[100];
	
		inf.getline(ch,100,'#');
		s1=unpack(ch);
	
	
		infile.getline(ch,100,'#');
		s2=unpack(ch);
	

	while(!inf.eof()&&!infile.eof()){
		if(atoi(s1.marks)<atoi(s2.marks)){
	
			pack(s1,a);
			outf<<a;
			{
			
			inf.getline(ch,50,'#');
			s1=unpack(ch);}
		}else{
			pack(s2,a);
			outf<<a;
			{
			
			infile.getline(ch,50,'#');
			s2=unpack(ch);}
		}
	}
	int k=0;
	
	while(!inf.eof()){
		if(infile.eof()){
		if(s2.marks<s1.marks&&k==0)
			{
			pack(s2,a);
			outf<<a;k=1;}
		
		else{
			pack(s1,a);
			outf<<a;
			inf.getline(ch,50,'#');
			s1=unpack(ch);
		}
	}
	}
	while(!infile.eof()){
		if(inf.eof()){
		if(s1.marks<s2.marks&&k==0){
		
		pack(s2,a);
		outf<<a;k=1;}
		else{
			inf.getline(ch,50,'#');
			s2=unpack(ch);
		}
}
	
	}
}
