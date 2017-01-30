#include<iostream>
using namespace std;
struct every{
int max;
int min;
int sum;
int avg;
};
struct every everything(int a[],every s,int size,int i)
{
if(i==size)
{
s.avg=s.sum/size;
return s;
}
if(a[i]<s.min)
s.min=a[i];
if(a[i]>s.max)
s.max=a[i];
s.sum +=a[i];
i++;
return everything(a,s,size,i);
}
int main()
{
int n;
cout<<"number of elements";
cin>>n;
int a[n];
cout<<" \n Enter the numbers";
for(int i=0;i<n;i++)
cin>>a[i];
int i=1;
struct every s;
s.max=s.min=a[0];
s.sum=a[0];
s.avg=0;
struct every s1 = everything(a,s,n,i);
cout<<endl<<" Max is "<<s1.max<<" Min is "<<s1.min<<" Sum is "<<s1.sum<<" avg ";
cout<<s1.avg;
return 0;
}
