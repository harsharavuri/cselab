#include<iostream>
#include<string.h>
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
	ifstream inf("sample.txt");
	ofstream outf("outputthird.txt");
	char ch[50];char c[10];student s;
	while(!inf.eof()){
		inf.getline(ch,50,'#');
		cout<<ch;
		int i=0;int j=0;
		while(ch[i]!='|'){
			s.roll[j]=ch[i];
			i++;j++;
		}
		s.roll[j]='\0';j=0;i++;
		while(ch[i]!='|'){
			s.name[j]=ch[i];i++;j++;
		}
		s.name[j]='\0';
		j=0;i++;
		
		while(ch[i]!='\0'){
			outf<<s.roll<<"|"<<s.name<<"|";
			while(ch[i]!='|'&&ch[i]!='\0'){
				s.marks[j]=ch[i];
				i++;j++;
			}
			s.marks[j]='\0';j=0;
			if(ch[i]=='\0'){
				outf<<s.marks<<"#";
			}else{
				outf<<s.marks<<"#";i++;
			}
		}
	
	}
}
