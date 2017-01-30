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
        int lines=0,words=0,chars=0;
	int fd = open(argv[i],O_RDONLY);
        if(fd==-1)break;
	char buff[2];char prev=' ';
	while((read(fd,buff,1)>0)){
		chars++;
		if(buff[0]=='\n'){
			if(prev!='\0' && prev!=' '){words++;}
			lines++;prev=' ';
                        cout<<prev<<"  ";
		}
	
		if(buff[0]==' ' && prev!=' ' && prev!='\0'){words++;}
		prev = buff[0];
	}
    	close(fd);
	cout<<lines<<" "<<words<<" "<<chars<<" "<<argv[i]<<endl;
	}
    return 1;	
}
