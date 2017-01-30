#include<bits/stdc++.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<iostream>
using namespace std;

bool functionLookUp(char* argv,char lookUp[][20]){
	for(int i=0;i<7;i++){
		if(strcmp(lookUp[i],argv)==0)return true;
	}
	return false;
}

void parse(char* line, char** argv){
  //cout<<"entered "<<line;
  while(*line!='\0'){
  //cout<<"entered1";
    while(*line == ' ' || *line=='\t' || *line=='\n')
	{*line='\0';line++;}
    *argv++ = line;
    //cout<<"tt";
    while(*line!=' ' || *line!='\t' || *line!='\n')
	line++;
  }
  *argv = '\0';
}

void execute(char **argv){
  int status;
  pid_t p;
  p = fork();
  if(p<0){
  	 cout<<"Error creating child)";exit(1);
	}else if(p>0){
		if(execvp(*argv, argv)<0){cout<<"Error";exit(0);}

	}else{	wait();
		//while(wait(&status)!=p);
	}
}

bool checkForwardSlash(char temp[], int size){
	for(int i=0;i<size;i++){
 	 if(temp[i]=='/'){
		return true;
	}
	}return false;
}

int main(void){
  string t;
  char line[100];
  char *argv[4];
  char lookUp[7][20] ={"bye", "ls", "rm", "kill", "ps", "wc", "cat"};
  while(1){
  bool check;
  gets(line);//strcpy(line, t.c_str());
  cout<<"yo0 \n";
  parse(line, argv);
  cout<<"aha";
  if(strcmp(argv[0], "bye")==0)
    {exit(0);}
  //if(isspace(argv[0]))continue;
  check = functionLookUp(argv[0], lookUp);
  if(!check){cout<<"Invalid command";continue;}	
 cout<<"yo2"<<endl;
   int size = sizeof(argv[1])+1;
  char temp[size];strcpy(temp, argv[1]);
  check = true;//check = checkForwardSlash(temp, size);
  if(!check){
  cout<<"Invalid file format";continue;
	}
  signal(SIGINT, SIG_IGN);
  signal(SIGTERM, SIG_DFL);
cout<<"last"<<endl;
  execute(argv);
}
}

