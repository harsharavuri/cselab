#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct student{
	int rollno;
	char* name;
	float cgpa;
};;
class file_class
{
	private:
		student stu;
		public:
			void set(int rno,char *nam, float cg)
			{
				stu.rollno = rno;
				stu.name = nam;
				stu.cgpa = cg;
			}
			student getvalue()
			{
				return stu;
			}
};
int main()
{
	char enter;
	cout<<"Do you want to modify? ";
	cin>>enter;
	char ch[100];
	int zw,id,n;
	if(!(enter=='y'|| enter=='Y'))
	{
	cout<<"Enter the number of students ";
	cin>>n;}
	else
	n=1;
	//ofstream outf("ff.txt");
	fstream outfile("ff.txt",ios::out|ios::binary|ios::in|ios::ate);
	int r;float c;
	file_class fil[n];
	for(int i=0;i<n;i++)
	{
		if(enter=='y'||enter=='Y')
		{
			cout<<"Enter the id of the student to be modified ";
			cin>>id;outfile.seekp(0);
			for(int i=0;i<id;i++)
			outfile.getline(ch,100);
			i=0;
		}
		cout<<"Enter the details of the student ";
		char *na;
		cin>>r>>na>>c;
		fil[i].set(r,na,c);
		student eg = fil[i].getvalue();
		int z = eg.rollno;
		strcpy(ch,eg.name);
		float zl = eg.cgpa;
		outfile<<z<<" "<<ch<<" "<<zl;
			if(enter=='y'||enter=='Y')
			i=n;
			else
			outfile<<"\n";
		}
		outfile.close();
	}
		
	


