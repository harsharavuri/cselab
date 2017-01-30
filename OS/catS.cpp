#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h> 
#include <fcntl.h>


using namespace std;
int main(int argc, char* argv[]){
    for(int i=1;i<argc;i++){
        int fd = open(argv[i],O_RDONLY);
        if(fd==-1)break;
	char buff[2];
	while((read(fd,buff,1)>0))cout<<buff[0];
    	close(fd);
	}
    return 1;	
}
