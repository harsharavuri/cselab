#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct student{
char name[8];
char roll[4];
char branch[5];
};

int main()
{      ofstream outf("fixedlength.txt");
	student s1;
cout<<"Enter the data of the students ";

cin>>s1.name>>s1.roll>>s1.branch;
int i=0;
while(s1.name[i]!='\0')
i++;
while(i<7)
{
s1.name[i] = '*';i++;
}
s1.name[i]='\0';
i=0;
while(s1.roll[i]!='\0')
i++;
while(i<3)
{
s1.roll[i]='*';i++;}
s1.roll[i]='\0';
i=0;
while(s1.branch[i]!='\0')
i++;

while(i<4)
{
s1.branch[i]='*';i++;}
s1.branch[i]='\0';

outf<<s1.name<<" "<<s1.roll<<" "<<s1.branch;
outf.close();
ifstream inf("fixedlength.txt");
char ch[10];
while(!inf.eof())
{
inf>>ch;
cout<<ch;}

return 1;
}
    
