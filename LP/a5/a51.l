
%{
#include <stdio.h>
int integers=0, floating=0, identifiers=0, operators=0; 

%}


%%

[0-9]+	{

	printf("Integer ");
	integers++;
}

([0-9]+(\.[0-9]+)?(e("+"|"-")?[0-9]+)?)	{
	printf("Floating point number ");
	floating++;
}

(([a-zA-z_])([0-9a-zA-z_])*)	{
	printf("identifiers ");
	identifiers++;
}

[\|&><,;\-\+=]	{
	printf("Operators ");
	operators++;
}


%%

int yywrap(){
	return 1;
}

int main(){
	printf("Enter text");
	yylex();
	printf("%d integers, %d operators, %d identifiers, %d floating", integers, operators, identifiers, floating);
	printf("Total: %d", operators+identifiers+integers+floating);
	return 0;
}
