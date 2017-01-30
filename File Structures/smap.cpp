#include<iostream>
#include<fstream>
using namespace std;
int main()
{int n=5;
	ifstream inf("smap.txt");int i=1;char l[3];
	while(i<5){
		inf>>l;i++;
		//if(inf.eof){
		cout<<l;
		}
	}
	//cout<<i;

