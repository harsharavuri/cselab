#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<iostream>
int buffersize=10;
sem_t full, empty;
pthread_mutex_t mutex;
int buff[buffersize];
int counter;
void initialise(){
    sem_init(&full,1,0);
    sem_init(&empty,1,buffersize);
    counter=0;
    pthread_mutex_init(&mutex,NULL);
    }

void write(int item){
    buffer[counter++]=item;
}

int read(){
    return buffer[--counter];
}

void producer((void*) param){
    int item = 1;
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    write(item);
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    }
    
void consumer((void*)param){
        int item;
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        item = read(item);
        pthread_mutex_unlock(&mutex);\
        sem_post(&full);
    }
    
int main(){
    
    pthread_t prod[10];
    pthread_t cons[10];
    for(int i=0;i<10;i++){
        
            pthread_create(&prod[i],NULL,&producer,NULL);
        
        }
    for(int i=0;i<10;i++){
        
            pthread_create(&cons[i],NULL,&producer,NULL);
        
        }
        
    for(int i=0;i<10;i++){
        
            pthread_join(prod[i],NULL);
        
        }    
    
    for(int i=0;i<10;i++){
        
            pthread_join(cons[i],NULL);
        
        }
        
    }    

