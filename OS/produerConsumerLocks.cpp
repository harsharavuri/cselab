#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<iostream>

#define buffersize 10
using namespace std;
//sem_t full, empty;
pthread_mutex_t mutex;
int buffer[buffersize];
int counter;
void initialise(){
//    sem_init(&full,1,0);
//    sem_init(&empty,1,buffersize);
    counter=0;
    pthread_mutex_init(&mutex,NULL);
    }

void write(int item){
    if(counter<buffercount){
    buffer[counter++]=item;
    cout<<"Produced ";
    return 1;
	}
    return -1;
}

int read(){
	if(counter>0){cout<<"Consumed ";
	return buffer[--counter];}
	return -1;
}

void* producer(void* param){
    int item = 1;int flag=-1;
    //sem_wait(&empty);
    while(flag==-1){
    pthread_mutex_lock(&mutex);
    flag=write(item);
    pthread_mutex_unlock(&mutex);
    //sem_post(&full);
   }
    }
    
void* consumer(void* param){
        int item=-1;
	while(item==-1){
	//sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item = read();
      	pthread_mutex_unlock(&mutex);
        //sem_post(&empty);
        }
    }
    
int main(){
    int flag=-1;
    initialise();
    pthread_t prod[10];
    pthread_t cons[10];
    for(int i=0;i<10;i++){
        
            pthread_create(&prod[i],NULL,producer,(void*)i);
        
        }
    for(int i=0;i<10;i++){
        
            pthread_create(&cons[i],NULL,consumer,(void*)i);
        
        }
        
    for(int i=0;i<10;i++){
        
            pthread_join(prod[i],NULL);
        
        }    
    
    for(int i=0;i<10;i++){
        
            pthread_join(cons[i],NULL);
        
        }
        
    }    

