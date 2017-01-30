d[0-9]
%{
int idcnt=0,kwcnt=0;int k=0;
%}

%%
^[0-9]*00$ {kwcnt++; printf("%s is a string ending in 00",yytext);}

^{d}*222{d}*$ {kwcnt++; printf("%s is a string with 222", yytext);}



^[0-9]*$     {		printf("Entered");int f2=0;
			  int sum=0;int f1=0, count;int dec=0;int y=1;
			  k=atoi(yytext);int a[100];int i=0;
			  while(k>0){
					a[i]=k%10;
					sum = sum+a[i];
					
					k=k/10;
					dec = dec+a[i]*y;
					if(a[i]!=0 || a[i]!=1)f2=1;
					y=y*2;i++;
				}
				printf("%d",dec);
				count=i;
			  int j;
			  //int f1=0;	
			  for(j=0;j<=count-5;j++){
				int c1=0;int k;
				for(k=j;k<j+5;k++){
					if(a[k]==5)c1++;
				}
				if(c1<2)f1=1;
                 	}
			if(count<5){
				int c1=0;int k;
				for(k=j;k<count;k++){
					if(a[k]==5)c1++;
				}
				if(c1<2)f1=1;
			}
			if(f1==0 && count>4){
				printf("Repetitive 5's");
				
			}else{
 
			  f1=0;
			  if(sum==9 && count==4){
				kwcnt++;printf("sum of digits of %s is 9", yytext);break;
				}else{	
			  for(i=0;i<3 && count==4;i++){
					if(a[i]<a[i+1]){f1=1;}
				}
			  if(f1==0 && count==4){
				kwcnt++;printf("Digits of %s are in asc order", yytext);
				}
				else if(dec%5==0 && f2==0 && !(f1==0 && count==4)){
					printf("Divisible by 5");
				}else{
				
			  k = atoi(yytext);
			  for(j=0;j<9;j++)k=k/10;
			  if(k%10 == 1){
				printf("10th from last is 1");
			  }
			}}
                          }
			}





%%

int main()
{
printf("Enter text");
yylex();
return 0;
}

