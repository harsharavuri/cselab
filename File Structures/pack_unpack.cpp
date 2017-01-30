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
	ifstream inf("first.txt");
	char ch[100];
	inf.getline(ch,100,'#');
	student s;
	s=unpack(ch);
	cout<<s.marks<<" "<<s.name<<" "<<s.roll<<endl;
	char b[100];
	pack(s,b);
	cout<<b;
}
