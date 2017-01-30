#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<iostream>
#include<unistd.h>
#define buffersize 10
using namespace std;
sem_t full, empty;
pthread_mutex_t mutex;
int buffer[buffersize];
int counter;
void initialise(){
    sem_init(&full,0,0);
    sem_init(&empty,0,buffersize);
    counter=0;
    pthread_mutex_init(&mutex,NULL);
    }

void write(int item){
    buffer[counter++]=item;
    cout<<"Produced ";
}

int read(){
	cout<<"Consumed ";
	return buffer[--counter];
}

void* producer(void* param){
    sleep(2);
	int item = 1;
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    write(item);
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    }
    
void* consumer(void* param){
        sleep(2);
		int item;
		sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item = read();
      	pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    
int main(){
    initialise();
    pthread_t prod[10];
    pthread_t cons[10];
    for(int i=0;i<10;i++){
        
            pthread_create(&prod[i],NULL,producer,(void*)i);
            pthread_create(&cons[i],NULL,consumer,(void*)i);
        
        }
    for(int i=0;i<10;i++){
        
        
        }
        
    for(int i=0;i<10;i++){
        
            pthread_join(prod[i],NULL);
        
        }    
    
    for(int i=0;i<10;i++){
        
            pthread_join(cons[i],NULL);
        
        }
        
    }    
