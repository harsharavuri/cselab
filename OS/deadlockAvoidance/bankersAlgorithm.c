#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>
#define n 5
#define m 10
int available[m];
int max[n][m];
int need[n][m];
int allocation[n][m];
int work[m];
int finish[n];
int request[n][m];

void initialise(){
	int i=0,j=0;
	for(i=0;i<n;i++)
		finish[i]=0;
	for(i=0;i<m;i++){
		available[i]=10;
		work[i]=available[i];
	}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			max[i][j]=3;
		}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			allocation[i][j]=1;
		}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			need[i][j]=max[i][j]-allocation[i][j];
		}
	
}

void requestInitialise(){
	int i=0,j=0;
	for(i=0;i<n;i++){
	for(j=0;j<m;j++)
		request[i][j]=2;
	}
}

int checkSafety(){
	int i=0,j=0;
	int check=0;
	for(i=0;i<n;i++){
		if(finish[i]!=0)continue;
		check=1;
		for(j=0;j<m;j++){
			if(need[i][j]>work[j]){
				break;
			}
		
		}
		if(j==m){
			break;
		}
	}
	if(check==1){
		printf("The system is in safe state");
		return 1;
	}
	if(j==m){

	finish[i]=1;
	for(j=0;j<m;j++){
		work[j]=work[j]+allocation[i][j];	
	}	
	}
	return 0;
}


int canBeGrantedSafely(int y){
	int i=0,j=0;
	for(i=0;i<m;i++){
		if(request[y][i]>need[y][i])break;
	}
	if(i!=m){
		printf("Not enough resources");
		return 0;
	}else{
		int check=0;
		while(check==0){
		for(i=0;i<m;i++){
			if(request[y][i]>available[i])break;
		}
		
		if(i!=m){
			printf("You probably have to wait");
			sleep(1);//return 1;
		}
		else{
			for(i=0;i<m;i++){
				available[i]=available[i]-request[y][i];
				allocation[y][i]=allocation[y][i]+request[y][i];
				need[y][i] = need[y][i]-request[y][i];
			}
			return 2;	
		}
		
		}
	}
}



int main(){
	initialise();
	while(checkSafety()==0);
}
