#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
union u{
	int salary;
	int wage;
};
int main()
{
	cout<<"Enter the number of employees details you want to enter";
	int n;string name;int salvage;
	cin>>n;
	u u1;
	ofstream outf("variablefield.txt");
	for(int i=0;i<n;i++){
		cout<<"For salary guy enter 1; for wage guy enter 2";
		int option;
		cin>>option;
		if(option==1){
			cout<<"Enter the name, employee number and the salary";
			cin>>name>>salvage>>u1.salary;
			outf<<option<<" "<<name<<" "<<salvage<<" "<<u1.salary;
		}
		else if(option==2){
			cout<<"Enter the name, employee number and the wage";
			cin>>name>>salvage>>u1.wage;
			outf<<option<<" "<<name<<" "<<salvage<<" "<<u1.wage;
		}
		outf<<endl;
	}
}

