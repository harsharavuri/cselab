#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>
#include<ucontext.h>
#include<unistd.h>
#define threads 5
int bursttime[threads];
int y[threads];
int i=0;
int turnaround[threads];
int entrytime[threads];
void* func(){
	printf("Task %d running \n", y[i]);
}
int main(){
	//pthread_mutex_t;
	pthread_t pthreads[5];
	for(i=0;i<5;i++){
		y[i]=i;
	}
	printf("Enter burst times first, later entry times \n");
	for(i=0;i<threads;i++){
		scanf("%d", &bursttime[i]);
	}
	for(i=0;i<threads;i++){
		scanf("%d", &entrytime[i]);
	}

	printf("Enter 1 for the threads at the same time, 2 for different entry time \n");
	int check;
	scanf("%d", &check);
	int j,k;
	if(check==2){
	turnaround[0]=0;
	for(j=1;j<threads;j++){
		
		
		/*for(k=0;k<5;k++){
			if(entrytime[j]>entrytime[k]){
				int temp = entrytime[j];entrytime[j]=entrytime[k];entrytime[k]=temp;
				
				}
			}
		}*/
	
	}}
	if(check==1){
		for(j=0;j<threads;j++){
			for(k=j+1;k<threads;k++)
			if(bursttime[j]>bursttime[k]){
				
				int temp=y[j];y[j]=y[k];y[k]=temp;
				temp = bursttime[j];bursttime[j]=bursttime[k]=bursttime[k];bursttime[k]=temp;
			
			}
		}
		printf("Check");
		for(i=0;i<threads;i++){
			printf("%d -", i);
			pthread_create(&pthreads[i],NULL,func,NULL);
			pthread_join(pthreads[i],NULL);
		}
	}

	

}
