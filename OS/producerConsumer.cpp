#include<iostream>
#include<stdio.h>

#include<semaphore.h>
#include<pthread.h>
using namespace std;
sem_t qlock;
int prod=1;
void* producer(void* i);
void* consumer(void* i);

class queue{
	public:
	int front=-1;
	int rear=-1;
	int size=10;
	int ar[10];
	void enqueue(int a){
		if(front==-1){
			front++;rear++;
			ar[front]=a;
		}else{
			front = (front+1)%size;
			ar[front]=a;
		}
	}
	int dequeue(){
		if(front==-1)return -1;
		if(front==rear)return -1;
		int temp= ar[rear];
		rear = (rear+1)%size;
		return temp;
	}
	int top(){
		if(front==rear)return -1;
		return ar[front];
	}
	
};
queue q;

int main(){
	int count=0;
	pthread_t prod, cons;
	sem_init(&qlock, 0, 1);
	pthread_create(&prod, NULL, producer, (void*) NULL);
	pthread_create(&cons, NULL, consumer, (void*) NULL);
	pthread_join(prod,NULL);
	pthread_join(cons, NULL);
	sem_destroy(&qlock);
}

void* producer(void* i){
	while(1){
	
		while((q.front+1)%q.size == q.rear)sem_wait(&qlock);
		sem_wait(&qlock);
		prod++;
		q.enqueue(prod);
		cout<<q.top()<<" Enqueued"<<endl;
		sem_post(&qlock);
		if(prod==30)exit(0);
	}
}

void* consumer(void* i){
	while(1){
		sem_wait(&qlock);
		int temp = q.dequeue();
		if(temp!=-1){
			cout<<temp<<" dequeued"<<endl;
		}
		cout<<" Full ";
		sem_post(&qlock);
		if(temp==30)exit(0);
	}
}
