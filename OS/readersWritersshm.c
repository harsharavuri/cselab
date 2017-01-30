#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <limits.h>

#define MAXPROCESSES 20000

#define ITERATIONS 100
#define INITVALUE 0UL
#define SEMKEY_MUTEX 0xDEADBEEF
#define SEMKEY_WRI   0xDEAFBABE

union semun {
  int              val;    
  struct semid_ds *buf;    
  unsigned short  *array;  
  struct seminfo  *__buf;  
};

void write_file(void);
void read_file(void);

int id_mutex, id_wri; 
int *rc;              
int readers=10, writers=10;


void P(int semid)
{
  struct sembuf mysemop;

  mysemop.sem_num = 0;
  mysemop.sem_op = -1; 
  mysemop.sem_flg = 0;
	
  if ( semop(semid, &mysemop, 1) == -1 ) {
//    fatal("P()");
  }
}

void V(int semid)
{
  struct sembuf mysemop;

  mysemop.sem_num = 0;
  mysemop.sem_op = 1;
  mysemop.sem_flg = 0;
  
  if ( semop(semid, &mysemop, 1) == -1 ) {
//    fatal("V()");
  }
}



void writer(void)
{
  int c;

  printf("Writer, PID %d, starts\n", getpid());

  for (c=0; c < ITERATIONS; c++) {
    P(id_wri);
//    write_file();
    V(id_wri);
  }
  printf("Writer, PID %d, finished\n", getpid());
  exit(EXIT_SUCCESS);
}

void reader(void)
{
  int c;

  printf("Reader, PID %d, starts\n", getpid());

  for (c=0; c < ITERATIONS; c++) {

    P(id_mutex);
    *rc += 1;
    if (*rc == 1) {
      P(id_wri);
    } 
    //printf("rc = %d\n", *rc);
    V(id_mutex);
	
	
    
    P(id_mutex);
    *rc -= 1;
    if (*rc == 0) {
      V(id_wri);
    } 
    V(id_mutex);
  }

  printf("Reader, PID %d, finished\n", getpid());
  exit(EXIT_SUCCESS);
}



int main(){
  pid_t son[MAXPROCESSES], tmppid;
  int c, ret, id_shm;
  union semun mysem;
  FILE *fin;
  unsigned long x;
  
  id_shm = shmget(IPC_PRIVATE, 4096, IPC_CREAT|0600);
  if (id_shm == -1) {
  
  }
  rc = (int*) shmat(id_shm, NULL, 0);
  if (rc == (void*) -1) {
  
  }

  id_mutex = semget(SEMKEY_MUTEX, 1, IPC_CREAT|S_IRUSR|S_IWUSR);
  if (id_mutex == -1) {
  }
  id_wri = semget(SEMKEY_WRI, 1, IPC_CREAT|S_IRUSR|S_IWUSR);
  if (id_wri == -1) {
  }

  mysem.val = 1;
  ret = semctl(id_mutex, 0, SETVAL, mysem);
  if (ret == -1) {
   // fatal("init mutex");
  }
  ret = semctl(id_wri, 0, SETVAL, mysem);
  if (ret == -1) {
   // fatal("init wri");
  }

  for (c=0; c<readers; c++) {
    tmppid = fork();
    if (tmppid == -1) {
     // fatal("fork a reader");
    }
    if (tmppid != 0) {
      son[c] = tmppid;
    }  
    else {
      reader(); 
    }
  }
  for ( ; c<readers+writers; c++) {
    tmppid = fork();
    if (tmppid == -1) {
     // fatal("fork a reader");
    }
    if (tmppid != 0) {
      son[c] = tmppid;
    }  
    else {
      writer(); 
    }
  }
    
  for (c=0; c<readers+writers; c++) {
    tmppid = wait(&ret);
   // printf("Son with PID %ld returned %d.\n", (long) tmppid, ret);
  }

  ret = shmdt((void*) rc);
  if (ret == -1) {
  }
  ret = shmctl(id_shm, IPC_RMID, NULL);
  if (ret == -1) {
  }

  ret = semctl(id_wri, 0, IPC_RMID);
  if (ret == -1) {
  }
  ret = semctl(id_mutex, 0, IPC_RMID);
  if (ret == -1) {
  }
   exit(EXIT_SUCCESS);
}
