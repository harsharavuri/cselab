#include<iostream>
#include<fstream>
using namespace std;
class stack{
	private:
		int size;
		char a[25];
		int top;
		public:
			stack(){
				top=-1;
				size=0;
			}
			int push(char ch){
			++top;
			if(top<size)
			{
			a[top]=ch;return 1;}
			else
			{	top--;
			return 0;}cout<<a[top];
			}
			char pop()
			{
				if(top==-1)
				return '0';
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
			void print()
			{
				for(int i=0;i<=top;i++)
				cout<<a[i];
				
			}
			
};
int main()
{
	cout<<"Enter the size of the stack";
	int n;
	cin>>n;
	stack s;
	s.set_size(n);
	
	
	int h=0;
	 cout<<"Enter the number of operators and operands";cin>>n;
        
         cout<<"Enter the string";
        char ch[20];
        cin>>ch;
        int i =0;
        while(ch[i]!='\0')
        {
        	if(ch[i]=='{'||ch[i]=='('||ch[i]=='[')
         {cout<<"ka";
         s.push(ch[i]);h=1;}
         else if(ch[i]=='}'||ch[i]==')'||ch[i]==']')
         {h=1;
         char l = s.pop(); cout<<" l "<<l;
         if(l!=ch[i])
         {
          cout<<" It is not balanced ";
           return 0;
         }
			
        }i++;
    }	
		if(h==1)
		{
			if(s.isempty())
			cout<<"It is balanced";
			else
			cout<<"It is inbalanced;";
		}
		
        }




