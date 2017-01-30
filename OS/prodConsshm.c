#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<bits/stdc++.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main(){
	int size = 4096;
	int id = shmget(IPC_PRIVATE, size, S_IRUSR|S_IWUSR);
	
}
