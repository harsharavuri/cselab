#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class employee{
	protected:
		string name;

		int empno;
		public:
			void setname(string c)
			{
				name = c;
			}
			string getname()
			{
				return name;
			}
			void set_emp(int n){
				empno= n;
			}
			int get_emp()
			{
			return empno;
			}
};
class e1:public employee{
	private:
		int bonus;
		public:
			void set_bonus(int b)
			{
				bonus =b;
			}
			int get_bonus(){
				return bonus;
			}
};
class e2:public employee{
	private:
		int nho;
		int holidays;
		public:
			void set_holidays(int h){
				holidays = h;
			}
			int get_holidays(){
				return holidays;
			}
			void set_nho(int n)
			{
				nho=n;
			}
			int get_nho(){
				return nho;
			}
			

};
int main()
{
	cout<<"Enter the number of records you want to enter";
	int n;e1 emp1;e2 emp2;
	ofstream outf("variableformat.txt");
	cin>>n;string name;int eno,bonus,holidays,nho;
	cout<<"Enter 1 for e1, 2 for e2.";
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the employee number you want to enter";
		int option;
		cin>>option;
		if(option==1){
			cout<<"Enter e1 details: name, eployee number and bonus";
			cin>>name>>eno>>bonus;
			emp1.setname(name);
			emp1.set_emp(eno);
			emp1.set_bonus(bonus);
			outf<<name<<" "<<eno<<" "<<" "<<bonus;
		}
		else if(option==2){
			cout<<"Enter e2 details: name, employee number, number of hours and holidays";
			cin>>name>>eno>>nho>>holidays;
			emp2.setname(name);emp2.set_emp(eno);emp2.set_holidays(holidays);emp2.set_nho(nho);
			outf<<name<<" "<<eno<<" "<<bonus;
		}
		outf<<endl;
	}
}
