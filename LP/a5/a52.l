
%{
	#include<stdio.h>
	int kwcnt = 0;

%}

%%

[ ]+	{
	printf(" ");
}

.	{
	printf("%s", yytext);
}

%%

int main(){

	yylex();
	return 0;

}
