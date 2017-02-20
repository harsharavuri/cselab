d[0-9]

%{

int idcnt=0,kwcnt=0;int k=0;
#include<stdio.h>

%}

%%




^[0-9]*00$ {kwcnt++; printf("%s is a string satisfied by a\n",yytext);}

^{d}*222{d}*$ {kwcnt++; printf("%s is string satisfied by b\n", yytext);}





^{d}*1[0-9]{9,9}$	{
		kwcnt++;printf("satisfied by f \n");
	}

{sumnine} {printf("satisfied by g \n");}
{increasingnumbers} {printf("string satisfied by h \n");}
{increasingnumbers2} {printf(" satisfied by h \n");}




%%

int main()
{
printf("Enter text");
yylex();
return 0;
}
