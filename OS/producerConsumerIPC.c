#include<stdio.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<pthread.h>

union semun {
  int              val;    
  struct semid_ds *buf;    
  unsigned short  *array;  
  struct seminfo  *__buf;  
};

struct prodcons{

	int in;
	int out;
	int a[10];
	int count;

};

int main(){
	int segmentid;//Identifies the shared memory id
	const int size = 4096;//sizeof(prodcons);
	segmentid = shmget(IPC_PRIVATE, size, S_IRUSR|S_IWUSR);
	
}
