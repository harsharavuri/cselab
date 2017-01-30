#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <limits.h>


union semun {
  int              val;    
  struct semid_ds *buf;    
  unsigned short  *array;  
  struct seminfo  *__buf;  
};

struct item{
	int count;
	int a[10];
}*ptr;

int semid;

struct sembuf waitfull, signalfull, waitempty, signalempty, waitmutex, signalmutex;

void* producer(void* arg){
	//while(1){
		//sleep(2);
		semop(semid, &waitempty,1);
		semop(semid, &waitmutex,1);
		ptr->a[ptr->count]=1;
		ptr->count++;
		printf("produced \n");
		semop(semid,&signalmutex,1);
		semop(semid, &signalfull,1);
		sleep(2);		
	//}
}

void* consumer(void* arg){
	//while(1){
		semop(semid, &waitfull, 1);
		semop(semid, &waitmutex,1);
		int val=ptr->a[ptr->count];
		ptr->count--;
		printf("consumed \n");
		semop(semid, &signalmutex,1);
		semop(semid, &signalempty, 1);
		sleep(2);
	//}
}

int main(){
	union semun mysem;
	int size = sizeof(struct item);
	int shmid = shmget(IPC_PRIVATE,size, IPC_CREAT|0666|IPC_EXCL );
	ptr = (struct item*)shmat(shmid, NULL, 0);
	ptr->count=0;
	semid = semget(IPC_PRIVATE, 3, IPC_CREAT|IPC_EXCL|0666);
 	mysem.val=1;
	semctl(semid, 0, SETVAL, mysem);
	mysem.val=1;	
	semctl(semid, 1, SETVAL, mysem);	
	mysem.val=10;
	semctl(semid, 2, SETVAL, mysem);
	waitmutex.sem_num=0;
	waitmutex.sem_op=-1;
	waitmutex.sem_flg=0; 
	signalmutex.sem_num=0;
	signalmutex.sem_op=1;
	signalmutex.sem_flg=0;
	waitfull.sem_num = 1;
	waitfull.sem_op=-1;
	waitfull.sem_flg=0;
	signalfull.sem_num = 1;
	signalfull.sem_op=1;
	signalfull.sem_flg=0;

	waitempty.sem_num = 2;
	waitempty.sem_op=-1;
	waitempty.sem_flg=0;
	signalempty.sem_num = 2;
	signalempty.sem_op=1;
	signalempty.sem_flg=0;
	pthread_t prod[10], cons[10];
	int i;
	for(i=0;i<10;i++){
		pthread_create(&prod[i],NULL, producer, NULL);
		pthread_create(&cons[i], NULL, consumer, NULL);
	}

	for(i=0;i<10;i++){
		pthread_join(prod[i], NULL);
		pthread_join(cons[i], NULL);
	}

}
