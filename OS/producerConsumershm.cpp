#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<bits/stdc++.h>

#include<sys/shm.h>
#include<sys/stat.h>

using namespace std;

int main(){
	int size = 4096;
	int id = shmget(IPC_PRIVATE, size, S_IRUSR|S_IWUSR);
	
}
