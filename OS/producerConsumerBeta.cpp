#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<iostream>
#include<unistd.h>
#define buffersize 10
using namespace std;
pthread_mutex_t full, empty;
pthread_mutex_t mutex;
int buffer[buffersize];
int counter;
void initialise(){
    pthread_mutex_init(&full,NULL);
    pthread_mutex_init(&empty,NULL);
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
    if(counter>=buffersize)    
        pthread_mutex_lock(&empty);
    pthread_mutex_lock(&mutex);
    write(item);
    pthread_mutex_unlock(&mutex);
    if(counter>0)	
		pthread_mutex_unlock(&full);
   
    }
    
void* consumer(void* param){
        sleep(2);
		int item;
		if(counter<=0)
			pthread_mutex_lock(&full);
        pthread_mutex_lock(&mutex);
        item = read();
      	pthread_mutex_unlock(&mutex);
        if(counter<buffersize)	
			pthread_mutex_unlock(&empty);
    }
    
int main(){
    initialise();
    pthread_t prod[10];
    pthread_t cons[10];
    pthread_mutex_lock(&full);
     for(int i=0;i<10;i++){
        
            pthread_create(&cons[i],NULL,consumer,(void*)i);
        
        }
    for(int i=0;i<10;i++){
        
            pthread_create(&prod[i],NULL,producer,(void*)i);
        
        }
   
        
    for(int i=0;i<10;i++){
        
            pthread_join(prod[i],NULL);
        
        }    
    
    for(int i=0;i<10;i++){
        
            pthread_join(cons[i],NULL);
        
        }
        
    }    
