#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(int argc, char* argv[]){
    if(argc<2){
        cout<<"File name must be entered";
	return -1;
    }
    for(int i=1;i<argc;i++){
    if(unlink(argv[i]) == 0){
        cout<<"Success, file is removed";
        
    }
    else {cout<<"There is an error while removing the files";
     }
    }
    return 0;
}
