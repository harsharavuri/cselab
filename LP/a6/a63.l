d ("10"|"11"|"12"|"13"|"14"|"15")

%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int lno=0;
int prev=-1;
%}


%%

[\n]	{
	lno++;
	prev=-1;
	printf("\n");
}

[0-9]|{d}	{
	if(prev==-1){
		prev = atoi(yytext);
	}else{
		int num = atoi(yytext)-prev;
		if(num>0){
			printf("+%d",num);
		}else if(num<0){
			printf("%d",num);
		}else{
			printf("0");
		}
		prev = atoi(yytext);
	}
	//printf("Feature %s",yytext);
}

.	{

}

%%

int yywrap(){
	return 1;
}

int main(){
	//printf("Enter text");
	yylex();
	//printf("Lines: %d ", lno);
	return 0;
}
