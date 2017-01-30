#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<iostream>
#include<unistd.h>
#define chairs 5
using namespace std;
sem_t barber,customer;
pthread_mutex_t mutex;
int waiting=0;
int count=0;
void* barber1(void* param){
	while(1){

	sem_wait(&customer);
	pthread_mutex_lock(&mutex);
	
	waiting=waiting-1;
	cout<<"Cut Hair \n";
	sem_post(&barber);
	pthread_mutex_unlock(&mutex);
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
		cout<<"waiting ";
		sem_wait(&barber);
		
	
	}else{
		pthread_mutex_unlock(&mutex);
	}	
}

int main(){
	sem_init(&barber,0,0);
	sem_init(&customer,0,0);
	pthread_mutex_init(&mutex,NULL);
	pthread_t barb,customers[5];
	pthread_create(&barb,NULL,barber1,NULL);
	for(int i=0;i<5;i++){
		pthread_create(&customers[i],NULL,customer1,NULL);
	}
	pthread_join(barb,NULL);
	for(int i=0;i<5;i++){
		pthread_join(customers[i],NULL);
	}
	
}
