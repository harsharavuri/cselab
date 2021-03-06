#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h> 
#define NUM_THREADS  4
#define COUNT_LIMIT 13
int     done = 0;
int     count = 0;
int     quantum = 2;
int     thread_ids[4] = {0,1,2,3};
int     thread_runtime[4] = {0,5,4,7};
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;

void * inc_count(void * arg);


static sem_t count_sem;


 int quit = 0;


void *inc_count(void *t) 
{
   long my_id = (long)t;
   int i;
   sem_wait(&count_sem);   
   printf("run_thread = %d\n",my_id);
   printf("%d \n",thread_runtime[my_id]);
   for( i=0; i < thread_runtime[my_id];i++)
      {
         printf("runtime= %d\n",thread_runtime[my_id]);
         pthread_mutex_lock(&count_mutex); 
         count++;
         if (count == COUNT_LIMIT) {
            pthread_cond_signal(&count_threshold_cv);
            printf("inc_count(): thread %ld, count = %d  Threshold reached.\n", my_id,
            count);
         }
      printf("inc_count(): thread %ld, count = %d, unlocking mutex\n",my_id, count);
      pthread_mutex_unlock(&count_mutex);
      sleep(1) ;
      }
   sem_post(&count_sem); 
   pthread_exit(NULL);
}


void *watch_count(void *t) 
{
  long my_id = (long)t;
  printf("Starting watch_count(): thread %ld\n", my_id);

  pthread_mutex_lock(&count_mutex);
  if (count<COUNT_LIMIT) {
     pthread_cond_wait(&count_threshold_cv, &count_mutex);
     printf("watch_count(): thread %ld Condition signal received.\n", my_id);
     printf("watch_count(): thread %ld count now = %d.\n", my_id, count);
     }
  pthread_mutex_unlock(&count_mutex);
  pthread_exit(NULL);
}



int main (int argc, char *argv[])
{
   int i;
   long t1=0, t2=1, t3=2, t4=3;
   pthread_t threads[4];
   pthread_attr_t attr;
   sem_init(&count_sem, 0, 1);
  
   pthread_mutex_init(&count_mutex, NULL);
   pthread_cond_init (&count_threshold_cv, NULL);
  
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
   pthread_create(&threads[0], &attr, watch_count, (void *)t1);
   pthread_create(&threads[1], &attr, inc_count, (void *)t2);
   pthread_create(&threads[2], &attr, inc_count, (void *)t3);
   pthread_create(&threads[3], &attr, inc_count, (void *)t4);
 
   for (i=0; i<NUM_THREADS; i++) {
      pthread_join(threads[i], NULL);
   }
   //printf ("Main(): Waited on %d  threads. Done.\n", NUM_THREADS);
  
   pthread_attr_destroy(&attr);
   pthread_mutex_destroy(&count_mutex);
   pthread_cond_destroy(&count_threshold_cv);
   pthread_exit(NULL);
  }
