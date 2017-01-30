#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
struct child{
	char nam[10];
	char number[4];
};
struct employee{
	char name[10];
	char number[5];

};
struct employee s1;
void pack(employee s,char a[])
{
   cout<<"Enter the name of the emp";
   cin>>s.name;
   strcpy(a,s.name);
   
   strcat(a,"|");

   cout<<"\n Enter number of the employee ";
   cin>>s.number;
   strcat(a,s.number);
   strcat(a,"|");
   child c;
   int option;
   cout<<"Enter the number of children";
   cin>>option;
  for(int i=0;i<option;i++){
  		cout<<"Enter the name and number of the child";
		  cin>>c.nam;
	  strcat(a,c.nam);
   strcat(a,"|");
	  cin>>c.number;
  	strcat(a,c.number);
   strcat(a,"|");
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
{fin.getline(c,50);
k++;}
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


int main()
{	employee e;char a[50];
/*ofstream outf("repeated_variable.txt",ios::app|ios::out);
	pack(e,a);
int i=0;
	while(a[i]!='#')
{
outf<<a[i];i++;
}
outf<<a[i];
outf.close();*/
ifstream inf("repeated_variable.txt");
  
  unpack(inf);
  inf.close();
//	pack(e,a);
	
}
