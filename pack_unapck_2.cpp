#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
struct student{
  char name[6];
   char roll[3];
   char branch[6];
};
struct student s1;

void pack(student s,char a[])
{
   cout<<"Enter the name of the student ";
   cin>>s.name;
   strcpy(a,s.name);
   
   strcat(a,"|");

   cout<<"\n Enter the roll number of the student ";
   cin>>s.roll;
   strcat(a,s.roll);
   strcat(a,"|");
  cout<<"\n Enter the branch of the student ";
   cin>>s.branch;
   strcat(a,s.branch);
   strcat(a,"#");
}
void unpack(ifstream & fin)
{
char c[50];
fin.getline(c,50);
cout<<"Enter the id of student you want to output";
int n;
cin>>n;
int k=0;int i=0;
while(k<n)
{
int j =0 ;
while(c[i]!='|')
{s1.name[j]=c[i];j++;
i++;}

s1.name[j] = '\0';
cout<<s1.name;
i++; j=0;
while(c[i]!='|')
{
s1.roll[j]=c[i];j++;
i++;
}
s1.roll[j] = '\0';
cout<<s1.roll;
i++;j=0;
while(c[i]!='#')

{
s1.branch[j] = c[i];
i++;j++;
}
s1.branch[j]='\0';
cout<<s1.branch;
i++;k++;
}
}
int main()
{
  ofstream outf("pack_unpack.txt",ios::out|ios::ate|ios::app);
  cout<<"Enter the data ";
student s;char a[50];
  pack(s,a);
  int i=0;
  while(a[i]!='#')
{
outf<<a[i];i++;
}
outf<<a[i];
outf.close();
ifstream inf("pack_unpack.txt");
  
  unpack(inf);
  inf.close();
  //cout<<s1.name<<s1.branch;
   return 0;
  }
