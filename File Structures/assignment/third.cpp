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
	ifstream inf("fixed.txt");
	ifstream infile("variable.txt");
	ofstream outf("output.txt");
	student s1,s2;char ch[50];char a[50];
	inf.getline(ch,50,'#');
	s1=unpack(ch);
	int i=0;

	while(s1.roll[i]!='*'){
	i++;}
	s1.roll[i]='\0';
	i=0;
	while(s1.name[i]!='*')i++;
	s1.name[i]='\0';
	while(s1.marks[i]!='*')i++;
	s1.marks[--i]='\0';
	
	infile.getline(ch,50,'#');
	s2=unpack(ch);
	while(!inf.eof()&&!infile.eof()){
		if(atoi(s1.marks)<atoi(s2.marks)){
	
			pack(s1,a);
			outf<<a;
			{
			
			inf.getline(ch,50,'#');
			s1=unpack(ch);
			int i=0;
			while(s1.roll[i]!='*')i++;
			s1.roll[i]='\0';
			i=0;
			while(s1.name[i]!='*')i++;
			s1.name[i]='\0';
			while(s1.marks[i]!='*')i++;
			s1.marks[--i]='\0';
			}
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
		
		pack(s1,a);
		outf<<a;
		{
			inf.getline(ch,50,'#');
			s1=unpack(ch);
		}
		int i=0;
		while(s1.roll[i]!='*')i++;
		s1.roll[i]='\0';
		i=0;
		while(s1.name[i]!='*')i++;
		s1.name[i]='\0';
		while(s1.marks[--i]!='*')i++;
		s1.marks[i]='\0';
		}
		while(!infile.eof()){
		pack(s2,a);
		outf<<a;
		if(!infile.eof()){
			inf.getline(ch,50,'#');
			s2=unpack(ch);
		}
	}
	
}
	

