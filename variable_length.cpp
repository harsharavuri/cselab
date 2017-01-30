#include<iostream>
#include<string.h>
#include<fstream>
struct student{
	char name[20];
	int roll;
	float cgpa;
};
using namespace std;
int main()
{
	ofstream outf("variablelength.txt");
	cout<<"Enter the number of records you want to enter";
	int n;student s1;
	cin>>n;
	char name[20];int roll; float cg;
	for(int i=0;i<n;i++){
		cout<<"Enter the name, roll number and cgpa";
		cin>>s1.name>>s1.roll>>s1.cgpa;
		outf<<s1.name<<" "<<s1.roll<<" "<<s1.cgpa;
		outf<<endl;
	}
	
}
