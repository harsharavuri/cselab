consonants [bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ]
vowels [aeiouAEIOU]

%{
#include <stdio.h>
#include <string.h>
#define buffsize 200
char buff[buffsize];
%}

%%



^{vowels}[a-zA-Z0-9]* {
				strcpy(buff,yytext);
				char fc = '\0';
				strcat(buff,"ay");
				printf("%s", buff);
			};


[ \t\n]{vowels}[a-zA-Z0-9]* {
				strcpy(buff,yytext);
				char fc = '\0';
				
				fc = buff[0];
				strcat(buff,"ay");
				printf("%c%s", fc, &buff[1]);
			};			

^{consonants}[a-zA-Z0-9]* {
				strcpy(buff,yytext);
				char fc = '\0';
				buff[yyleng] = buff[0];
				buff[yyleng+1] = '\0';
				strcat(buff,"ay");
				printf("%s",&buff[1]);
			};

[ \n\t]{consonants}[a-zA-Z0-9]* {
				strcpy(buff,yytext);
				char fc = '\0';
				fc = buff[0];
				buff[yyleng] = buff[1];
				buff[yyleng+1] = '\0';
				strcat(buff,"ay");
				printf("%c%s",fc,&buff[2]);
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
	//execvp("./a53", NULL);
	return 0;
}