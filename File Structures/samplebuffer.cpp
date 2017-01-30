#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
int main(){
	char a[10]="bas";
	char b[10]="has";
	ofstream outf("sample_file.txt");
	outf<<"abcde#fghij#klmno#";
	outf.close();
	fstream f("sample_file.txt");
	f.getline(a,10,'#');
	cout<<f.tellg();
	char ch=f.get();
	cout<<"  "<<ch;
}
