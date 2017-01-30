#include<iostream>
#include<string>
#include<fstream>
using namespace std;





int main()
{
	char data[100];
	int vowels=0,conson=0,words=1,lines=1;

	cout<<"Enter the string ";
	cin.getline(data,100);
	
	ofstream outfile("count.txt");
	outfile<<data;
	outfile.close();
	int k =0;
	ifstream ifile("count.txt");
	while(!ifile.eof())
	{
		char ch;
		if(k==0)
		{
		ifile.get(ch);
		}
		if(k==1)
		k=0;
		if( ch == 'a' || ch == 'e' || ch == 'i' ||ch == 'o' || ch=='u')
		vowels++;
		if(ch>'a' && ch<='z' && ch!='e' && ch!='i' && ch!='o' && ch!= 'u'  )
		conson++;
		if(ch==' ')
		{
		words++;
		
		while(ch==' ')
		{
			ifile.get(ch);
			k=1;
		}
	}
		
		if(ch == '\n')
		{
			words++;
			lines++;
		}
		
	
}
		
		
	
	cout<<" THe number of words "<<words<<" Number of consonents "<<conson<<" Vowels "<<vowels<<" LInes "<<lines;
	
	
}
