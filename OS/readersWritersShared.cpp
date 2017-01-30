
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

#define RESSFILE "zahl.dat"
#define ITERATIONS 100
#define INITVALUE 0UL

#define SEMKEY_MUTEX 0xDEADBEEF
#define SEMKEY_WRI   0xDEAFBABE

/* The calling program must define union semun */
union semun {
  int              val;    /* Value for SETVAL */
  struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
  unsigned short  *array;  /* Array for GETALL, SETALL */
  struct seminfo  *__buf;  /* Buffer for IPC_INFO
			      (Linux-specific) */
};

/* some prototypes */
void fatal(char*);
void write_file(void);
void read_file(void);

/*
   global resources 
*/
int id_mutex, id_wri;     /* semids of semaphores */
int *rc;                  /* reader counter in shm segment */
unsigned long readers, writers;
/*
    a fatal error has occured -> exit 
*/
void fatal(char *msg)
{
  assert (msg != NULL);

  perror(msg);
  exit(EXIT_FAILURE);
}

/*
    a non-fatal error has occured -> warn, but continue
*/
void nonfatal(char *msg)
{
  assert (msg != NULL);

  perror(msg);
  return;
}

void P(int semid)
{
  struct sembuf mysemop;

  mysemop.sem_num = 0;
  mysemop.sem_op = -1; 
  mysemop.sem_flg = 0;
	
  if ( semop(semid, &mysemop, 1) == -1 ) {
    fatal("P()");
  }
}

void V(int semid)
{
  struct sembuf mysemop;

  mysemop.sem_num = 0;
  mysemop.sem_op = 1;
  mysemop.sem_flg = 0;
  
  if ( semop(semid, &mysemop, 1) == -1 ) {
    fatal("V()");
  }
}

void writer(void)
{
  int c;

  printf("Writer, PID %d, starts\n", getpid());

  for (c=0; c < ITERATIONS; c++) {
    P(id_wri);
    write_file();
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
    printf("rc = %d\n", *rc);
    V(id_mutex);

    read_file();

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

int main(int argc, char* argv[])
{
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
    fatal("semget mutex");
  }
  id_wri = semget(SEMKEY_WRI, 1, IPC_CREAT|S_IRUSR|S_IWUSR);
  if (id_wri == -1) {
    fatal("semget wri");
  }

  /* init mutex and wri as "open" */
  mysem.val = 1;
  ret = semctl(id_mutex, 0, SETVAL, mysem);
  if (ret == -1) {
    fatal("init mutex");
    /* XXX remove semaphore set */
  }
  ret = semctl(id_wri, 0, SETVAL, mysem);
  if (ret == -1) {
    fatal("init wri");
    /* XXX remove semaphore set */
  }

  /* create processes, readers first */
  for (c=0; c<readers; c++) {
    tmppid = fork();
    if (tmppid == -1) {
      fatal("fork a reader");
    }
    if (tmppid != 0) {
      /* Father */
      son[c] = tmppid;
    }  
    else {
      reader(); 
      assert(0); /* may not be reached, because reader() terminates */
    }
  }
  /* only father reaches this */

  /* create writers processes */
  for ( ; c<readers+writers; c++) {
    tmppid = fork();
    if (tmppid == -1) {
      fatal("fork a reader");
    }
    if (tmppid != 0) {
      /* Father */
      son[c] = tmppid;
    }  
    else {
      writer(); 
      assert(0); /* may not be reached, because writer() terminates */
    }
  }
    
  /* only father reaches this */

  /* wait for children to terminate */
  for (c=0; c<readers+writers; c++) {
    tmppid = wait(&ret);
    printf("Son with PID %ld returned %d.\n", (long) tmppid, ret);
  }

  /* detach and delete shared memory segment */
  ret = shmdt((void*) rc);
  if (ret == -1) {
    fatal("shmdt");
  }
  ret = shmctl(id_shm, IPC_RMID, NULL);
  if (ret == -1) {
    fatal("delete shared memory segment");
  }

  /* destroy the semaphores */
  ret = semctl(id_wri, 0, IPC_RMID);
  if (ret == -1) {
    fatal("delete semaphore wri");
  }
  ret = semctl(id_mutex, 0, IPC_RMID);
  if (ret == -1) {
    fatal("delete semaphore mutex");
  }

  /* open shared file and check its final value */
  fin = fopen(RESSFILE, "r");
  if (fin == NULL) {
    nonfatal("main, fopen for check");
  }

  ret = fscanf(fin, "%lu", &x); /* returns # of converted items */
  if (ret != 1) {
    nonfatal ("main, fscanf while checking");
  }

  fclose(fin);

  if (x == writers*ITERATIONS) {
    printf("Correct value %ld in %s reached.\nDeleting.", x, RESSFILE);
    ret = unlink(RESSFILE);
    if (ret == -1) {
      fatal("unlink");
    }
  }
  else {
    printf("Incorrect value %ld in %s .\n", x, RESSFILE);
    printf("Leaving file for inspection.\n");
  }

  exit(EXIT_SUCCESS);
}

