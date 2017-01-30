#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
void compress(ifstream & inf){
	int k;
	int l;
	ofstream outf("run_compress.txt");
	while(!inf.eof()){
		int c=0;
		inf>>k;
		if(inf.eof())
		outf<<k<<" ";
		else{
			inf>>l;
			cout<<l<<" "<<k<<" ";
			if(l==k){
				while(l==k&&!inf.eof()){
				c++;inf>>l;
			}
			cout<<"f:"<<l<<":"<<c<<" ";
			outf<<"f:"<<l<<":"<<c<<" ";
			//if(!inf.eof())
			//inf>>l;
		}
		else{
			
			outf<<k<<" "<<l<<" ";
			//if(!inf.eof())
			//inf>>l;
		}	
	}
}
}
int main(){
	ofstream outf("encodeinput.txt",ios::out);
	cout<<"Enter the number of elements ";
	int n;
	cin>>n;
	char ch[10];
	cin>>ch;
	outf<<ch;
	for(int i=1;i<n;i++){
		cin>>ch;
		outf<<" "<<ch;
	}
	outf.close();
	ifstream inf("encodeinput.txt");
	//compress(inf);
	int h=0;
	int z=0;
	char c;char l[10];char k[10];
	ofstream outfile("run_compress.txt");
	while(!inf.eof()){
		if(h==0)
		inf>>k;
		int c=0;
		if(!inf.eof())
			{
			inf>>l;
			z=strcmp(k,l);
			if(z==0){
				while(z==0&&!inf.eof()){
					c++;
					inf>>l;
					z=strcmp(k,l);
				}
				outfile<<"f:"<<l<<":"<<c;
				h=0;
			}
			else{
				outfile<<k<<" ";
				strcpy(k,l);
				h=1;
			}
	
			}
			else{
				outfile<<k<<" ";
			}
		}
	
	
	
	
}
