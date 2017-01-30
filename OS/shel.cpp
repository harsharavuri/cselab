#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int getArgs(char* argv[], char ch[]){
	int i=0,k=0;
	while(ch[i]!='\0'){
		char temp[20];int j=0;
		while(ch[i]!='\0' && ch[i]!=' '){
			temp[j++]=ch[i++];
		}
		temp[j]='\0';
		argv[k]=new char[20];
		strcpy(argv[k],temp);
		k++;
		if(ch[i]!='\0')i++;
	}
	argv[k]=NULL;
	return k;
}

bool checkBackSlash(char ch[]){
	int i=0;
	while(ch[i]!='\0'){
		if(ch[i]=='\\')return true;
		i++;
	}
	return false;
}

int main(){
	cout<<"Enter the command";
	char ch[100];
	//gets(ch);
	char* argv[5];
	while(1){
	cout<<endl<<"--";
	gets(ch);
	if(checkBackSlash(ch)==true){cout<<"No Back Slashes";continue;}
	int k = getArgs(argv, ch);

	if(strcmp(*argv, "exit")==0){
		cout<<"Exit ";return 0;
	}
	pid_t p;int status;
	p=fork();
	if(p<0){
		cout<<"Error creating process ";
	}
	else if(p>0){
		while(wait(&status)!=p);
		cout<<"Child process completed "<<endl;
	}else{
		if(execvp(*argv, argv) < 0){
			cout<<"Error";
		}
		
		}
	}
	return 0;
	}

