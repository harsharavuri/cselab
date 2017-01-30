#include<iostream>
#include<fstream>
using namespace std;
struct student{
char name[8];
char roll[3];
char branch[4];
};

int main()
{
ofstream outf("vlength.txt",ios::out|ios::ate|ios::app);
student s;
cout<<"Enter the data of the student ";
cin>>s.name>>s.roll>>s.branch;

outf<<s.name<<" "<<s.roll<<" "<<s.branch<<" ";
outf.close();
ifstream inf("vlength.txt");
char ch[10];
while(!inf.eof())
inf>>ch;
cout<<ch;
return 0;
}
