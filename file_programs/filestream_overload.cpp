#include<iostream>
using namespace std;
class student
{  public:
    char name[5];
    int roll;
    char branch[5];
    friend istream & operator>>(istream &fin, student &s);
    friend ostream &operator<<(ostream &fout, student &s);
};


istream & operator>>(istream &fin, student &s)
{
cout<<"Enter name";
fin>>s.name;
cout<<"Enter roll number";
fin>>s.roll;
cout<<"Enter branch";
fin>>s.branch; return fin;
}
ostream & operator<<(ostream &fout, student &s)
{
fout<<s.name;
fout<<s.roll;
fout<<s.branch;
return fout;
}
int main()
{
student s;
cin>>s;
cout<<s;
}


