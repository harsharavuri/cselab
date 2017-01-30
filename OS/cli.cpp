#include<bits/stdc++.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<iostream>
using namespace std;
int main(int argc, char* argv[]){
	char s[100];
	cout<<"Enter the command";
	cin>>s;
	pid_t p = fork();
	if(p<0){
		cout<<"error";return 0;
	}else if(p>0){
		cout<<"Waiting for the child to execute";
		wait();
		cout<<"Child executed";
	}else{
		
		if(!strcmp(s,"ls") || !strcmp(s,"wc") || strcmp(s,"rm") || strcmp(s,"kill")){
		char arg0[30];cin>>arg0;
		execlp(s,s,arg0,(char*)0);
	}else if(!strcmp(s,"cat")){
		char arg0[30];char arg1[30];cin>>arg0;cin>>arg1;
		cout<<arg0<<arg1<<endl;
		execlp(s,s,arg0,arg1,(char*)0);
		}else{
			execlp(s,s,(char*)0);
		}	
	
	}
	}

