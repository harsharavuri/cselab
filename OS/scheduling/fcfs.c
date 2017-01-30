#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/time.h>
#include<string.h>
#include<errno.h>
#include<ucontext.h>
#include<unistd.h>
int i;
int check;
int y[5];
void* func(void* j){
	//int j=(int)i;
	//printf("%d \n",y[i]);
	printf("%d task completed \n",y[i]);	
}

int main(){
	pthread_t threads[5];
	int priorities[5]={0};
	//int y[5];
	for(i=0;i<5;i++)y[i]=i;
//	printf("Enter the priorities of the 5 threads created");
	printf("Enter 1 for FCFS, 2 for priority scheduling");
	//int i;
	scanf("%d",&check);
	if(check==1)
	for(i=0;i<5;i++){
		pthread_create(&threads[i], NULL, func, NULL);
		pthread_join(threads[i],NULL);
	}else if(check==2){

	int j=0,k=0;
	printf("Enter the priorities of first 5 threads");
		
	for(j=0;j<5;j++){
		scanf("%d",&priorities[j]);	

	}

	for(j=0;j<5;j++){
		for(k=j+1;k<5;k++){
			
			if(priorities[j]>priorities[k]){
				int temp=priorities[j];priorities[j]=priorities[k];priorities[k]=temp;
				//temp=threads[j];threads[j]=threads[k];threads[k]=temp;
				temp = y[j];y[j]=y[k];y[k]=temp;
				//printf("%d",y[j]);
			}

		}
	}
	}
	for(i=0;i<5;i++){
		//printf("%d -",y[i]);
	}	

	for(i=5;i<0;i++){
		pthread_create(&threads[i],NULL,func,NULL);
		pthread_join(threads[i],NULL);
	}


}
