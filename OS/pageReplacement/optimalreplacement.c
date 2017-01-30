#include<stdio.h>
#include<conio.h>
#define max 3
int a[50],s[max];
int count,n,i;
int len(int);
int maxl(int,int,int);
int main()
{
  int j;
  int s0,s1,s2,t,d;
  count=max;
  printf("\nEnter the length of reference string: ");
  scanf("%d",&n);
  printf("\nEnter the reference string:\n");
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
  for(i=0;i<max;i++)
      s[i]=a[i];
  printf("\n\nafter 3 page faults \t\t stack: |_%d_|",s[0]);
  printf("\n Page number : %d",s[1]); 
  printf("\n Page number : %d",s[2]); 
  for(i=max;i<n;i++)
  {
    d=0;
    for(j=0;j<max;j++)
    {
      if(s[j]==a[i])
          d=1;
    }
    if(d==0)
    {
    s0=len(s[0]);
    s1=len(s[1]);
    s2=len(s[2]);
    t=maxl(s0,s1,s2);
    s[t]=a[i];
    count++;
    printf("\n\n%d inserted <page fault= %d> \t stack: %d",a[i],count,s[0]);
    printf("\n %d",s[1]); 
    printf("\n %d",s[2]); 
    }
    
  } 
  printf("\n\nTotal no of page faults: %d",count);
  getch();
}

int len(int k)
{
   int d,y=0;
   for(y=i+1;y<n;y++)   
     {
        if(a[y]==k)
            {
                d=(y-count);
                break;
            }
         else 
            d=n;
      }
  return d;
}


int maxl(int a,int b,int c)
{
  int r;
  if(a>=b&&a>=c) r=0;
  else if(b>=a&&b>=c) r=1;
  else if(c>=a&&c>=b) r=2;
  return r;
}
                 
  
 
      
  
