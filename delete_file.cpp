#include<iostream>
#include<string.h>
#include <fstream>
using namespace std;
struct student{
  char name[8];
  char number[5];
   char un[10];
};
union u{
	int salary;
	int wage;
};
struct student s1;
void pack(student s,char a[])
{
   cout<<"Enter the name of the student ";
   cin>>s.name;
   strcpy(a,s.name);
   
   strcat(a,"|");

   cout<<"\n Enter the number of the employee ";
   cin>>s.number;
   	
   strcat(a,s.number);
   strcat(a,"|");
	cout<<"For salary guy enter 1; for wage guy enter 2";
		int option;
		cin>>option;  
  		cout<<"Enter the value";
  		cin>>s.un;
		
   
   strcat(a,s.un);
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
s1.number[j]=c[i];j++;
i++;
}
s1.number[j] = '\0';
cout<<s1.number;
i++;j=0;
while(c[i]!='#')

{
s1.un[j] = c[i];
i++;j++;
}
s1.un[j]=
'\0';
cout<<s1.un;
i++;k++;
}
}

int main()
{	student s2;
	
fstream outfile("deleterecord.txt",ios::out|ios::in|ios::binary);
cout<<"Enter the number of the field you want to update";
int y;
cin>>y;
char ca[50];
for(int i=0;i<y;i++){
	outfile.getline(ca,50,'#');
}
//cout<<ca;
char a[50];
//cin>>a;
cout<<"Enter the data ";
//pack(s2,a);
int j=0;
//while(a[j]!='\0')
//{
//outfile<<a[j];j++;
//}
while(ca[j]!='\0'){
	outfile<<" ";j++;
}

outfile.close();

  
  return 0;
}



