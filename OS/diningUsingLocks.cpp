#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<iostream>
#include<unistd.h>
#include<semaphore.h>
using namespace std;
int count=0;
int n=5;
pthread_mutex_t in[5];
pthread_mutex_t mutex;
void* philosopher(void* i);
void take_fork(int i);
void put_fork(int i);
 int state[5]={0};
void test(int i);
int main(){
    pthread_t philosophers[5];
   
    pthread_mutex_init(&mutex,NULL);
    for(int i=0;i<5;i++){
        pthread_mutex_init(&in[i],NULL);    
    }
    for(int i=0;i<5;i++){
        pthread_create(&philosophers[i],NULL,philosopher,(void*)i);    
    }
    for(int i=0;i<5;i++){
        pthread_join(philosophers[i],NULL);
    }
       
    pthread_mutex_destroy(&mutex);
    for(int i=0;i<5;i++){
        pthread_mutex_destroy(&in[i]);    
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

    pthread_mutex_lock(&mutex);
    //sem_wait(in[i]);
    state[i]=1;
    cout<<i<<" is hungry";
    test(i);
    pthread_mutex_unlock(&mutex);
    pthread_mutex_lock(&in[i]);
    
}

void test(int i){

    if(state[i]==1 && state[(i+1)%5]!=2 && state[(i+4)]%5!=2){
        state[i]=2;    
    	cout<<i<< " is eating "<<endl;
    }
    //sleep(2);
    pthread_mutex_unlock(&in[i]);    
    
}

void put_fork(int i){
    
    pthread_mutex_lock(&mutex);
    state[i]=0;
    cout<<"Releasing fork";   
    test((i+1)%5);
    test((i+4)%5);
    pthread_mutex_unlock(&mutex);
    
}
