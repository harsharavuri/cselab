#include<iostream>
#include<fstream>
#include<string.h>
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
	cout<<"Enter the number of records ";
	int n;
	cin>>n;
	char a[50];
	ofstream outf("input.txt");
	student s;
	for(int i=0;i<n;i++){
		cin>>s.name>>s.roll>>s.marks;
		pack(s,a);
		outf<<a;
	}
	outf.close();
	ifstream inf("input.txt");
	ofstream of("output.txt");
	student s1[n];
	for(int i=0;i<n;i++){
		inf.getline(a,50,'#');
		s1[i]=unpack(a);
	}
	int j=0;
	student sec;
	for(int i=0;i<n;i++){
		
		for(int j=i+1;j<n;j++){
			if(strcmp(s1[j].roll,s1[i].roll)==1){
				sec=s1[i];
				s1[i]=s1[j];
				s1[j]=sec;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(i==0)
		{
			of<<s1[i].roll<<"|"<<s1[i].name<<"|"<<s1[i].marks;
		}else{
			if(strcmp(s1[i].roll,s1[i-1].roll)==0){
				of<<"|"<<s1[i].marks;	
			}else{
				of<<"#"<<s1[i].roll<<"|"<<s1[i].name<<"|"<<s1[i].marks;
			}
		}
	}
	
}
