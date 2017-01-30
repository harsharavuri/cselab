#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>
#include<ucontext.h>
#include "thqueue.c"
#define MAX_THREADS 10
#define STACK_SIZE 64000
ucontext_t Main;
int alloc[MAX_THREADS];
void createTask(struct Task* target, void(*fn)(void*)){
	if(getcontext(&(target->threads_context))==-1){
		printf("getcontext error \n");
		exit(1);
	}
	(target->threads_context).uc_stack.ss_sp = malloc(STACK_SIZE);
	(target->threads_context).uc_stack.ss_size = STACK_SIZE;
	(target->threads_context).uc_stack.ss_flags = 0;
	int id=-1;
	while(++id<10 && alloc[id]!=0);
	if(id==10){
		printf("Not enough space");
		exit(1);
	}
	target->thread_id=id;
	alloc[id]=1;
	
}
int main(int argc, char* argv[]){
	
}
