
%{

#include <stdio.h>
#include <string.h>
int lno=0;
int len=0;
char largest[100];
int features=0;
%}


%%

[\n]	{
	lno++;
	features=0;
	printf("\n");
}

"+"+0{0,3}("-")+	{
	printf("Feature %s",yytext);
	if(strlen(yytext)>len){
		len = strlen(yytext);
		strcpy(largest, yytext);
	}
	//features++;
}

.	{

}

%%

int yywrap(){
	return 1;
}

int main(){
	printf("Enter text");
	//strcpy("largest", "");
	yylex();
	printf("Lines: %d ", lno);
	printf("Largest feature: %s", largest);
	return 0;
}
