#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int main(){
	ifstream inf("eninput.txt");
	ofstream outf("enoutput.txt");
	int a;int b;
	inf>>a;inf>>b;
	while(!inf.eof()){
		int c=1;
		if(a==b)
		{
		while(a==b&&!inf.eof())
		{
			c++;
			inf>>b;
		}
		outf<<a<<":"<<c<<" ";
		a=b;inf>>b;
		
		}
		else
		{	outf<<a<<" ";
			a=b;
			inf>>b;
		}
	}
	
}
