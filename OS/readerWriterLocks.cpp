#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <iostream>
using namespace std;
pthread_mutex_t databaseAccess;
pthread_mutex_t readcountAccess;
int readCount=0;
void* Reader(void*);
void* Writer(void*);
int main(){
        int nor, now;
        pthread_t readers[100],writers[100];
        pthread_mutex_init(&databaseAccess,NULL);
        pthread_mutex_init(&readcountAccess,NULL);
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

        pthread_mutex_destroy(&databaseAccess);
        pthread_mutex_destroy(&readcountAccess);

	}

	void* Writer(void* i){
        //sleep(1);
        pthread_mutex_lock(&databaseAccess);
        //cout<<*i;
        int temp = (int) i;
        printf(" Performing operations on the database \n");
        pthread_mutex_unlock(&databaseAccess);


}

void* Reader(void* i){
        //sleep(1);
        pthread_mutex_lock(&readcountAccess);
        readCount++;
        int temp = (int) i;
        if(readCount==1){
                pthread_mutex_lock(&databaseAccess);
                printf(" Database access obtained \n");
        }
        pthread_mutex_unlock(&readcountAccess);
        printf("Reader job finished \n");
        pthread_mutex_lock(&readcountAccess);
        readCount--;
        if(readCount==0)pthread_mutex_unlock(&databaseAccess);
        pthread_mutex_unlock(&readcountAccess);

}

