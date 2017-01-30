#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream numbers("sort_files.txt");
	int n;
	cout<<"Enter the number of elements you want to input";
	cin>>n;
	int k;
	cout<<endl<<"Enter the numbers";
	for(int i=0;i<n;i++)
	{
		cin>>k;
		numbers<<k<<" ";
	}
	numbers.close();
	ifstream num("sort_files.txt");
	int data[n];
	int i =0;
	int ch;
	while(num>>ch)
	{	
		data[i]=ch;
		i++;
		
	}
	int j,l;
	for(j=0;j<i;j++)
	cout<<data[j];
	cout<<endl<<i<<endl;
	
	for(j=0;j<i;j++)
	{
	
	for(l=j+1;l<i;l++)
	{
		if(data[l]>data[j])
		{	int temp;
			temp = data[l];
			data[l]= data[j];
			data[j] = temp;
		}
	}
	
	}
	for(j=0;j<i;j++)
	cout<<data[j];
	num.close();
	ofstream num_x("sort_files.txt");
	for(j=0;j<i;j++)
	{
		num_x<<data[j];
		num_x<<"\n";
	}
	return 0;
	
}
