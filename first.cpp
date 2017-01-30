#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream inf("records.txt");
	ifstream infile("numbers.txt");
	int n;
	char c[100];infile>>n;
	while(!inf.eof()&&!infile.eof()){
		
		for(int i=0;i<n;i++){
			inf.getline(c,100);
			cout<<c<<"\n";
		}
		cout<<"--------------------------------- \n" ;
		infile>>n;
	}
	return 0;
}
