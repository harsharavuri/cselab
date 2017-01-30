#include<iostream>
#include<iomanip>
using namespace std;
int year;
int leap(int y)
{
	if((y%4==0 &&y%100!=0)||y%400==0)
	return 1;
	else
	return 0;
}
void display()
{
	cout<<endl<<setw(4)<<"Sun"<<setw(4)<<"Mon"<<setw(4)<<"Tue"<<setw(4)<<"Wed"<<setw(4)<<"Thu"<<setw(4)<<"Fri"<<setw(4)<<"Sat"<<endl;
}
void m_display(int x)
{
	cout<<endl<<endl<<endl;
	switch(x)
	{
		case 1: cout<<"January"<<year;break;
		case 2: cout<<"February"<<year;break;
		case 3: cout<<"March"<<year;break;
		case 4: cout<<"April"<<year;break;
		case 5: cout<<"May"<<year;break;
		case 6: cout<<"June"<<year;break;
		case 7: cout<<"July"<<year;break;
		case 8: cout<<"August"<<year;break;
		case 9: cout<<"September"<<year;break;
		case 10: cout<<"October"<<year;break;
		case 11: cout<<"November"<<year;break;
		case 12: cout<<"December"<<year;break;	
	}
	cout<<endl;
}
int main()
{
	int mtrack[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
	int month = 0;
	int day = 4,date,k;
	cout<<endl<<"Enter the year";
	cin>>year;
	int y1 =1970;
	while(y1<1970)
	{
		day++;
		if(day==7)
		day=0;
		if(leap(y1))
		day++;
		if(day==7)
		day=0;
		y1++;
	}
	if(leap(year))
	mtrack[1]=29;
	while(month<12)
	{
		date =1;
		m_display(month+1);
		display();
		k=1;
		while(date<=mtrack[month])
		{
			if(date==1)
			cout<<setw(4*day+3)<<date<<" ";
			else
			cout<<setw(3)<<date<<" ";
			date++;
			day++;
			if(day==7)
			{
				cout<<endl;
				day=0;
			}
		}month++;
	}
	return 0;
}
