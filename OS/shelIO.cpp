#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdio.h>
#include<sys/stat.h>
#include<iostream>
#include<string.h>
using namespace std;

int changeIO(char ch[], int i){
	char temp[40];

	char check=ch[i];
	char check2=ch[i+1];
	for(int j=0;j<i;j++)ch++;
	while(*ch=='>' || *ch=='<')ch++;
	while(*ch==' ')ch++;
	int fd, b;//int fd=open(ch);int b;
	if(check=='>' && check2=='>')b= 1;
	else if(check=='<')b= 0;
	else if(check=='>' && check2!='>')b=2;
	//cout<<"bbbbb    "<<b<<endl;
	//cout<<"chsajdklsajkldjsajdkljsakdjksalasd "<<ch<<endl<<endl;
	if(b==1)fd=creat(ch, 0644);
	if(b==0)fd=open(ch, O_RDONLY);
	if(b==2)fd=open(ch,O_WRONLY | O_APPEND);

	if(b==1 || b==2)b=1;
	int y = dup2(fd,b);
	cout<<fd<<"yyyyyyyyyy "<<endl;
	//int yo = execlp("ls","ls",(char*)0);
	//cout<<yo<<" yosadsadasdsa ";
	//echo "  yo";
	return y;
	//return b;
}

int getArgs(char* argv[], char ch[]){
	int i=0,k=0;
	while(ch[i]!='\0'){
		char temp[20];int j=0;
		while(ch[i]!='\0' && ch[i]!=' ' && ch[i]!='>' && ch[i]!='<'){
			temp[j++]=ch[i++];
		}
		temp[j]='\0';

		if(ch[i]=='>' || ch[i]=='<'){
			changeIO(ch, i);
			break;
		}		

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
	//if(checkBackSlash(ch)==true){cout<<"No Back Slashes";continue;}
	//int k = getArgs(argv, ch);

	if(strcmp(ch, "exit")==0){
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
	}else	{
		if(checkBackSlash(ch)==true){cout<<"No Back Slashes";continue;}
		int k = getArgs(argv, ch);
		if(execvp(*argv, argv) < 0){
			cout<<"Error";
		}
		
		}
	}
	return 0;
	}

