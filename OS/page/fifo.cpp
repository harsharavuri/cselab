#include<stdio.h>
#include<conio.h>
int search(int [],int);
void insert(int [],int);
void display(int []);
int a[10],fault=0,count=0;   
int n;
int main()
{
    int flag=0,page;
    printf("\nEnter number of frames : ");
    scanf("%d",&n);
    printf("\nEnter page numbers, -1 to stop)");
    printf("\n\nEnter page no:");
    scanf("%d",&page);
    do
    {
                  flag=search(a,page);
                  if(flag==0)
                      insert(a,page);
                   display(a);
                   printf("\n\nEnter page no :");
                   scanf("%d",&page);
    }while(page!=-1);
    printf("\nTotal no of page faults : %d",fault);
    getch();
}
                                                                                       
int search(int a[],int page)
{
	int i;
    if(count==0)
        return 0;
    else
    {
        for(i=0;i<count;i++)
            if(a[i]==page)
                    return 1;
    }
    return 0;                      
}                                                                            
void insert(int a[],int page)
{
     int i,j;
     if(count==0)
        a[count]=page;
     else if(count!=n)
        a[count]=page;
     else
        {
          for(i=0,j=1;j<n;i++,j++)
              a[i]=a[j];
          a[i]=page;
          count--;
          fault++;
	
		}
     count++;
}            

void display(int a[])
{
     int i;
     for(i=count-1;i>=0;i--)
       printf("\npage no:%d",a[i]);
}
                                   
