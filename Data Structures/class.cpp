#include<iostream>
#include<fstream>
using namespace std;
class stack{
	private:
		int size;
		struct element a[25];
		int top;
		public:
			stack(){
				top=-1;
				size=0;
			}
			int push(){
			++top;
			if(top<size)
			{
			a[top]=ch;return 1;}
			else
			{	top--;
			return 0;}
			}
			struct pop()
			{
				if(top==-1)
				return 0;
				else
				{
					return a[top--];
				}
			}
			void set_size(int k)
			{
				size = k;
			}
			int isempty()
			{
				if(top==-1)
				return 1;
				else return 0;
			}
			//void print()
		//	{
			//	for(int i=0;i<=top;i++)
			//	cout<<a[i];
				
		//	}
			
};
struct element{
	union post;int tag;
};
union post{
	int number;
	char exp;
};
int main()
{
	cout<<"Enter the size of the stack";
	int n;
	cin>>n;
	stack s;
	s.set_size(n);
}
