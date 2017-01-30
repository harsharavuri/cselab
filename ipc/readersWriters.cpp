#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <iostream>
using namespace std;
sem_t databaseAccess;
sem_t readcountAccess;
int readCount=0;
void* Reader(void*);
void* Writer(void*);
int main(){
	int nor, now;
	pthread_t readers[100],writers[100];
	sem_init(&databaseAccess,0,1);
	sem_init(&readcountAccess,0,1);
	cout<<"Enter the number of readers and writers";
	cin>>nor>>now;
	for(int i=0;i<nor;i++){
		pthread_create(&readers[i],NULL,Reader, (void*) i);
	}
	for(int i=0;i<nor;i++){
		pthread_join(readers[i],NULL);
	}

	for(int j=0;j<now;j++){
		pthread_create(&writers[j],NULL, Writer, (void*) j);

	}

	for(int j=0;j<now;j++){
		pthread_join(writers[j],NULL);
	}

	sem_destroy(&databaseAccess);
	sem_destroy(&readcountAccess);

}

void* Writer(void* i){
	//sleep(1);
	sem_wait(&databaseAccess);
	//cout<<*i;
	cout<< " Performing operations on the database";
	sem_post(&databaseAccess);


}

void* Reader(void* i){
	//sleep(1);
	sem_wait(&readcountAccess);
	readCount++;
	if(readCount==1){
		sem_wait(&databaseAccess);
		cout<<"Database access obtained ";
	}
	sem_post(&readcountAccess);
	cout<<"Reader job finished";
	sem_wait(&readcountAccess);
	readCount--;
	if(readCount==0)sem_post(&databaseAccess);
	sem_post(&readcountAccess);

}
