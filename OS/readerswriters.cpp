#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <iostream>
#include<unistd.h>
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
                pthread_create(&writers[i],NULL, Writer, (void*) i);
        }
      /*  for(int j=0;j<now;j++){
                pthread_create(&writers[j],NULL, Writer, (void*) j);

        }*/
		for(int i=0;i<nor;i++){
                pthread_join(readers[i],NULL);
        }
 	

        for(int j=0;j<now;j++){
                pthread_join(writers[j],NULL);
        }

        sem_destroy(&databaseAccess);
        sem_destroy(&readcountAccess);

	}

	void* Writer(void* i){
        
        cout<<sem_wait(&databaseAccess);
        
        int temp = (int) i;
        cout<< temp<<" Performing operations on the database "<<endl;
        sem_post(&databaseAccess);


}

void* Reader(void* i){
        
        sem_wait(&readcountAccess);
        readCount++;
        int temp = (int) i;
        if(readCount==1){
                sem_wait(&databaseAccess);
                cout<<temp<< " Database access obtained "<<endl;
        }
        sem_post(&readcountAccess);
        cout<<"Reader job finished \n"<<endl;
        sleep(5);
        sem_wait(&readcountAccess);
        readCount--;
        if(readCount==0)sem_post(&databaseAccess);
        sem_post(&readcountAccess);
        

}

