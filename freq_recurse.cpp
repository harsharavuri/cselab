#include<iostream>
using namespace std;int b[100];int n;
int freq(int a[],int i,int e, int c[])
{
if(i==n)
{
for(int j=0;j<e;j++)
{
cout<<"The frequency of "<<b[j]<<" "<<c[j]<<endl;
}
return 0;
}
int l;
for(int j=0;j<i;j++)
{
if(a[i]==b[j])
l=-1;
}
if(l==-1)
i++;
else{
b[e]=a[i];c[e]=0;
for(int j=0;j<n;j++)
{
if(a[i]==a[j])
c[e]++;
}
e++;i++;
}
return freq(a,i,e,c);
}
int main()
{

cout<<"Enter the number of elements";
cin>>n;
int a[n];int c[n];
cout<<"Enter the elements ";
for(int l=0;l<n;l++)
cin>>a[l];
int e=0;int i=0;
freq(a,i,e,c);
return 0;
}

