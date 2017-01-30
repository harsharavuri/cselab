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
	ifstream inf("single.txt");
	char ch[50];
	student s1,s2;
	ofstream outf("output.txt");
	inf.getline(c,50,"#");
	s2=unpack(c);
	
	if(s2.name!=s1.name||s2.roll!=s1.roll){
		pack(s1,a);
		outf<<a;
		s1=s2;
	}
	else{
		outf<<s1.name<<"|"<<s1.roll<<"|";
		while(s2.name==s1.name&&s2.roll==s1.roll&&!inf.eof()){
			outf<<s2.marks;
			if(inf.eof);else{
				inf.getline(c,10,'#');
				if(s2.name==s1.name&&s2.roll==s1.roll){
					outf<<"|";
				}
			}
			
		}
		outf<<"#";
		s1=s2;
	}
	if(inf.eof){
		outf<<s1.roll<<"|"<<s1.name<<"|"<<s1.marks<<'#';
	}
	if(s1==s2){
		outf<<s1.marks<<"#";
	}	
	else if{
	}
	
}
