d[0-9]
%{
int idcnt=0,kwcnt=0;int k=0;
%}

%%
^[0-9]*00$ {kwcnt++; printf("%s is a string ending in 00",yytext);}

^{d}*222{d}*$ {kwcnt++; printf("%s is a string with 222", yytext);}


^(55{d}{d}{d}|5{d}5{d}{d}|5{d}{d}5{d}|5{d}{d}{d}5|{d}55{d}{d}|{d}5{d}5{d}|{d}5{d}{d}5|{d}{d}55{d}|{d}{d}5{d}5|{d}{d}{d}55)*$	{

		kwcnt++;printf("contains atleast two 5s for every block of 5");
	}

^[0-9]*$     {		printf("Entered");
			  int sum=0;int f1=0, count;int dec=0;int y=1;
			  k=atoi(yytext);int a[100];int i=0;
			  while(k>0){
					a[i]=k%10;
					sum = sum+a[i];
					i++;
					k=k/10;
					dec = dec+a[i]*y;
					y=y*2;
				}
				count=i;
			  if(sum==9 && count==4){
				kwcnt++;printf("sum of digits of %s is 9", yytext);
				}	
			  for(i=0;i<3 && count==4;i++){
					if(a[i]<a[i+1]){f1=1;}
				}
			  if(f1==0 && count==4){
				kwcnt++;printf("Digits of %s are in asc order", yytext);
				}
				if(dec%5==0 && !(f1==0 && count==4)){
					printf("Divisible by 5");
				}
				


                          }





^{d}*1[0-9]{9,9}$	{
		kwcnt++;printf("10th digit from the end is 1");
	}

%%

int main()
{
printf("Enter text");
yylex();
return 0;
}
