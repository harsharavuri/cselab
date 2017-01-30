#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/time.h>
#include<string.h>
#include<errno.h>

#include "thqueue.c"
#include<ucontext.h>
#define MAX_THREADS 10
#define STACK_SIZE 64000
#define TIME_SLOT 500000   
typedef struct Task* Tptr;

int CURRENT_THREAD_COUNT=0;
int TERMINATED=0;
int Global_id;


 ucontext_t Main; 

 ucontext_t Delete[MAX_THREADS]; 
 int alloc[MAX_THREADS];
struct itimerval alarm;

struct sigaction sched_signal;


struct Tque    ready_queue;
struct Task     *Current_Thread=NULL;

void schedule()
{

 if(Current_Thread==NULL) 
 {
  TERMINATED=0;
  if(!isempty(&ready_queue))       
  {
   Current_Thread=top(&ready_queue);

   Global_id=Current_Thread->thread_id;

   swapcontext(&Main, &(Current_Thread->threads_context));
  }
  else                
  {

   setcontext(&Main);
  }
 }
 else     
 {
  struct Task* tmp=next(&ready_queue, Current_Thread);

  if(tmp==NULL)  
  {    

   if(TERMINATED==1)
   {

    TERMINATED=0;
    remov(&ready_queue, Global_id);
    Current_Thread=NULL;
    setcontext(&Main);
   }
   else
   {
    struct Task* tmp1=Current_Thread;
    Current_Thread=NULL;
    swapcontext(&(tmp1->threads_context), &Main); 
   }
   
  }
  else
  {
   struct Task* tmp2=Current_Thread;
   Current_Thread=tmp;
   if(TERMINATED==1)
   {
    TERMINATED=0;
    remov(&ready_queue, Global_id);
    Global_id=tmp->thread_id;

    setcontext(&(tmp->threads_context));
   }
   else
   {
    Global_id=tmp->thread_id;

    swapcontext(&(tmp2->threads_context), &(tmp->threads_context)); 
   }
   
  }
 }
}

void Kill_Task(void *arg)
{

 int t_id=*((int*)arg);

 TERMINATED=1;
 schedule();
}


void Init_Task()
{
 sched_signal.sa_handler=schedule;
 sigemptyset(&sched_signal.sa_mask);
 sched_signal.sa_flags=0;
 sigaction(SIGPROF, &sched_signal, NULL);
 ready_queue.count=0;
 int i=-1;
 while(++i<MAX_THREADS)
  alloc[i]=0;

 alarm.it_value.tv_sec=0;
 alarm.it_value.tv_usec=TIME_SLOT;
  alarm.it_interval.tv_sec=0;
 alarm.it_interval.tv_usec=TIME_SLOT;

}

void Init_Semaphore(struct Task_Semaphore* mut, int value)
{
 mut->count=value;
 
}

void change_Semaphore(struct Task_Semaphore* mut, int value)
{
 sigset_t old, new;
 sigemptyset(&new);
 sigaddset(&new, SIGPROF);
 sigprocmask(SIG_BLOCK, &new, &old);
 if(mut->count > value)
 {
  mut->count-=value;
  sigprocmask(SIG_SETMASK, &old, NULL);
  return;
 }
 else
 {
  insert(&(mut->wait_queue), rem_and_poi(&ready_queue, Current_Thread));
  sigprocmask(SIG_SETMASK, &old,NULL);
  schedule();
 }
}
void create_task(struct Task* target, void (*fn)(void*), void * param)
{


  if(getcontext(&(target->threads_context))==-1)
  {
   printf("getcontext error!\n");
   exit(1);
  }
  
  (target->threads_context).uc_stack.ss_sp=malloc(STACK_SIZE);
  (target->threads_context).uc_stack.ss_size=STACK_SIZE;
  (target->threads_context).uc_stack.ss_flags=0;

  

  int id=-1;
  while(++id<10 && alloc[id]!=0);

  if(id==10)
  {
   printf("allocation error\n");
   exit(1);
  }
  target->thread_id=id;
  alloc[id]=1;

  if(getcontext(&Delete[id])==-1)
  {
   printf("delete context error!\n");
   exit(1);
  }
  
  Delete[id].uc_link=0;
  Delete[id].uc_stack.ss_sp=malloc(STACK_SIZE);
  Delete[id].uc_stack.ss_size=STACK_SIZE;
  Delete[id].uc_stack.ss_flags=0;
  (target->threads_context).uc_link=&Delete[id];
  makecontext(&Delete[id], (void*)&Kill_Task, 0);
  makecontext(&(target->threads_context), fn, 0);

  target->next=NULL;

  if(CURRENT_THREAD_COUNT++==0)
  {
    if(setitimer(ITIMER_PROF, &alarm, NULL)==-1)
    {

     printf("Itimer error:%s", strerror(errno));
     exit(1);
    }

  }

  sigset_t new,old;
  sigemptyset(&new);
  sigaddset(&new, SIGPROF);
  sigprocmask(SIG_BLOCK, &new, &old);
  if(isempty(&ready_queue)!=0)
  {

   insert(&ready_queue, target);
  }
  else
  {

   insert(&ready_queue, target);
  }

  sigprocmask(SIG_SETMASK, &old, NULL);
}  


int Sigh=0;
void sample()
{
 printf("success!!\n");
 while(Sigh==0);
 printf("completed!!\n");

}

void samps()
{
 
 printf("success2\n");
 Sigh=1;
}
void sam3()
{
 printf("started3\n");

 printf("success3\n");
}
int main(int argc, char *argv[])
{
 Init_Task();
 struct Task t,p,q;
 int a=5;
 create_task(&t, (void*)&sample, (void*)&a);
 create_task(&p, (void*)&samps, (void*)&a);
 create_task(&q, (void*)&sam3, (void*)&a);

 printf("yeasss\n");
 while(1);

}



