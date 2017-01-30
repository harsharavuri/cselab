#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream outfile("country.txt");
	ofstream city("capital.txt");
	string a,b;
	char ch;
	do
	{
		cout<<"Enter the name of the country and the respective capital ";
		cin>>a>>b;
		outfile<<a<<"\n";
		city<<b<<"\n";
		cout<<"Enter y if you want to enter data ";
		cin>>ch;
		
	}while(ch=='y'||ch=='Y');
	cout<<endl;
	outfile.close();
	city.close();
	ofstream merge("merge_files.txt");
	ifstream con("country.txt");
	ifstream cit("capital.txt");
	while(con>>a)
	{
		cit>>b;
		merge<<"The name of the country is "<<a<<" and its respective capital is "<<b<<" \n";
	}
	cit.close();
	con.close();
	
	return 0;
}
