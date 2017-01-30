#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	ofstream orig("original.txt");
	char t[100];
	cout<<"Enter the string which is to be trimmed ";
	cin.getline(t,100);
	orig<<t;
	orig.close();
	ifstream ori("original.txt");
	ofstream trim("trimmed.txt");
	char data[100];
	ori.getline(data,100);
	
	char ch;
	char k;
	char str[100];
	int l =0;
	ori.close();
	ifstream o("original.txt");
	int z = 0;
	while(o.get(ch))
	{	
		if(l==1)
		{
			str[z] = k;
			z++;
			l=0;
		}
		str[z] = ch;
		z++;
		
		if(ch == ' ')
		{
			while(ch==' ')
			{
			o.get(ch);
			k = ch;
			l=1;
		}
	}
}

	for(int i=0;i<z;i++)
	{
		k = str[i];
		trim.put(k);
	}
	
	return 0;
}

