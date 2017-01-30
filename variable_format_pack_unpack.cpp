#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
struct student{
   char name[6];
   char roll[3];
   char branch[6];
};
struct stu{
	char name[6];
    char roll[3];
    char intern[10];
    char fee[5];
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
   stu s2;
   int option;
   cout<<"For student 1, press 1, else press 2";
   cin>>option;
   if(option==1){
   cout<<"\n Enter the branch of the student ";
   cin>>s.branch;
   strcat(a,s.branch);}
   else if(option==2){
   	cout<<"Enter the intern firm and the fees respectively";
   	cin>>s2.intern>>s2.fee;
   	strcat(a,s2.intern);strcat(a,"|");strcat(a,s2.fee);strcat(a,"|");
   }
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
while(c[i]!='#'){

if(c[i]=='|')
{s1.name[j]='\0';
cout<<s1.name;
j=0;i++;}
else {
s1.name[j]=c[i];

j++;
i++;}

}
s1.name[j]='\0';
cout<<s1.name;j++;
k++;
i++;
}

}
int main()
{
  ofstream outf("sample_pack_unpack.txt",ios::out|ios::ate|ios::app);
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
ifstream inf("sample_pack_unpack.txt");
  
  unpack(inf);
  inf.close();
 
  return 0;
}


