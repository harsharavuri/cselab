#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<iostream>
using namespace std;
int count=0;
int n=5;
sem_t in[5];
sem_t mutex;
void* philosopher(void* i);
void take_fork(int i);
void put_fork(int i);
 int state[5]={0};
void test(int i);
int main(){
    pthread_t philosophers[5];
   
    sem_init(&mutex,0,1);
    for(int i=0;i<5;i++){
        sem_init(&in[i],0,1);    
    }
    for(int i=0;i<5;i++){
        pthread_create(&philosophers[i],NULL,philosopher,(void*)i);    
    }
    for(int i=0;i<5;i++){
        pthread_join(philosophers[i],NULL);
    }
       
    sem_destroy(&mutex);
    for(int i=0;i<5;i++){
        sem_destroy(&in[i]);    
    }
    
}

void* philosopher(void* i){
 
    int temp = (int) i;
    while(1){
          //sleep(1);
          take_fork(temp);
          //sleep(2);
          put_fork(temp);  
    	count++;
    	if(count==100)exit(0);
	}   
    
}

void take_fork(int i){

    sem_wait(&mutex);
    //sem_wait(in[i]);
    state[i]=1;
    cout<<i<<" is hungry";
    test(i);
    sem_post(&mutex);
    sem_wait(&in[i]);
    
}

void test(int i){

    if(state[i]==1 && state[(i+1)%5]!=2 && state[(i+4)]%5!=2){
        state[i]=2;    
    	cout<<i<< " is eating "<<endl;
    }
    //sleep(2);
    sem_post(&in[i]);    
    
}

void put_fork(int i){
    
    sem_wait(&mutex);
    state[i]=0;
    cout<<"Releasing fork";   
    test((i+1)%5);
    test((i+4)%5);
    sem_post(&mutex);
    
}
