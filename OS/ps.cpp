#include<bits/stdc++.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main(int argc, char* argv[]){
    DIR* dir;
    struct dirent* myfile;
    dir = opendir(argv[1]);
    	 DIR* temp;
	 struct dirent* myf;
	 char buff[100];strcpy(buff,"");
	 strcat(buff, argv[1]);
	 strcat(buff,"/");
         char b[20];
	 strcat(buff,myfile->d_name);
	 temp = opendir(buff);
          
	 if(temp!=NULL){
		while((myf=readdir(temp))!=NULL){
			if(!strcmp(myf->d_name,"status")){
				 strcat(buff,"/status");
				 ifstream ifi(buff);
				 char tm[100];
				 if(atoi(myf->d_name)>0){ifi.getline(tm,'\n');cout<<tm<<"  ";}
				 ifi.getline(tm,'\n');cout<<tm<<endl;
			}
		}

	 } 
    }
}
