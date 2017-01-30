#include<iostream>
using namespace std;
union un_1{
int k;
char l;};
union un_3h{
int z;
float x;
};
struct s2{
char f;
int g;
};
struct s_2{
union un_3h h;int tag_un3;};
union un_2{
struct s_2 s_3;
struct s2 ss2;
};

struct s1
{
int a;
union un_1 b;
union un_2 *c;
union un_1 *d;
float e;
int tag_un1;
int tag_un2;
};
int main()
{
struct s1 s;
s.d = new(un_1);
s.c = new(un_2);
s.d = &(s.b);
s.tag_un2 = 1;
s.c->ss2.g=9;
cout<<endl<<s.c->ss2.g;
return 0;
}
