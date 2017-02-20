consonants [bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ]
vowels [aeiouAEIOU]

%{
#include <stdio.h>
#include <string.h>
#define buffsize 200
char buff[buffsize];
%}

%%



{vowels}[a-zA-Z]*[ \t\n] {
				strcpy(buff,yytext);
				char endc = '\0';
				if(buff[yyleng-1] == ' ' || buff[yyleng-1] == '\t'
				|| buff[yyleng-1] == '\n' )
				{
					endc = buff[yyleng-1];
					buff[yyleng-1] = '\0';
				}
				strcat(buff,"ay");
				printf("%s%c", buff, endc);
			};

{consonants}[a-zA-Z]*[ \t\n] {
				strcpy(buff,yytext);
				char endc = '\0';
				if(buff[yyleng-1] == ' ' || buff[yyleng-1] == '\t'
				|| buff[yyleng-1] == '\n' )
				{
					endc = buff[yyleng-1];
					buff[yyleng-1] = '\0';
				}
				//strcat(buff," ");
				buff[yyleng-1] = buff[0];
				strcat(buff,"ay");
				printf("%s%c",&buff[1],endc);
			};

. printf("%s",yytext);

[\n] printf("\n");

%%
int yywrap()
{
	return 1;
}
int main(int argc, char const *argv[])
{
	yylex();
	return 0;
}