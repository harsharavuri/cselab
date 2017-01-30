#include<iostream>
using namespace std;
struct home_adr
{
	int f;
	char i[20];
};
struct hostel_adr
{
	int k;
	char j;
};
struct addr
{
	struct home_adr home_k;
	struct hostel_adr *hos;
	struct home_adr *hom;
};
struct stud
{
	int rollno;
	char name[15];
	struct addr *adr;
	float cgpa;
};
int main()
{
	stud s;
	s.adr = new(addr);
	s.adr->hos = new(hostel_adr);
	s.adr->hom = new(home_adr);
	s.adr->home_k.f = 6;
	s.adr->hom = &(s.adr->home_k);
	//cout<<s.adr->hom<<endl<<&(s.adr->home_k)<<endl<<&s<<endl<<endl<<s.adr->hom->f;
	s.adr->hos->k = 12;
	cout<<"Value of k "<<s.adr->hos->k;
	cout<<" Enter the roll number, name and cgpa respectively";
	cin>>s.rollno>>s.name>>s.cgpa;
	cout<<endl<<"Enter the values k and j of hostel address ";
	cin>>s.adr->hos->k>>s.adr->hos->j;
	cout<<endl<<" Emter the values f and i of home address";
	cout<<endl;
	cin>>s.adr->home_k.f>>s.adr->home_k.i;
	return 0;
	
}
