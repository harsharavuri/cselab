#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct student{
char name[7];
char roll[3];
char branch[4];
};

int main()
{
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

while(s1.roll[i]!='\0')
i++;
while(i<3)
{
s1.roll[i]='*';i++;}
while(s1.branch[i]!='\0')
i++;
while(i<4)
{
s1.branch[i]='*';i++;}
cout<<endl<<s1.name<<s1.roll<<s1.branch;
return 1;
}
                    
