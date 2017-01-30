#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#define chairs 5
sem_t barber,customer;
pthread_mutex_t mutex;
int waiting=0;
int count=0;
void* barber1(void* param){
	while(1){

	sem_wait(&customer);
	pthread_mutex_lock(&mutex);
	sleep(2);
	waiting=waiting-1;
	sem_post(&barber);
	pthread_mutex_unlock(&mutex);
	printf("Cut Hair");
	count++;
	if(count==5)break;
	
	}
	
	
}
void* customer1(void* param){

	pthread_mutex_lock(&mutex);
	if(waiting<chairs){
		waiting=waiting+1;
		sem_post(&customer);
		
		pthread_mutex_unlock(&mutex);
		sem_wait(&barber);
		printf("Get Hair Cut");
	
	}else{
		pthread_mutex_unlock(&mutex);
	}	
	sleep(2);
}

int main(){
	sem_init(&barber,0,0);
	sem_init(&customer,0,0);
	pthread_mutex_init(&mutex,NULL);
	pthread_t barb,customers[5];
	pthread_create(&barb,NULL,barber1,NULL);
	int i;
	for(i=0;i<5;i++){
		pthread_create(&customers[i],NULL,customer1,NULL);
	}
	pthread_join(barb,NULL);
	for(i=0;i<5;i++){
		pthread_join(customers[i],NULL);
	}
	
}
