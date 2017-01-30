#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<ucontext.h>
#define threads 5
#define timeinterval 3
int times[threads];
int tinterval=timeinterval;
int i;
void* func(){
	
	printf("Task %d completed \n", i);
}


int main(){
	printf("Input %d time bursts", threads);
	for(i=0;i<threads;i++){
		scanf("%d", &times[i]);
	}
	int check=1;
	while(1){
		if(check == 0)break;
		check=0;
		for(i=0;i<threads;i++){
			if(times[i]>0){
				times[i]=times[i]-timeinterval;
				func();
				check=1;
			}
		}
	}
}
