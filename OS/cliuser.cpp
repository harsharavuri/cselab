#include<bits/stdc++.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<iostream>
#include<fcntl.h>
#include<string.h>
using namespace std;
int ls(int argc, char* argv[]){
    DIR* dir;
	cout<<argv[0];
    //struct stat mystat;
    struct dirent* myfile;
    dir = opendir(argv[0]);
    cout<<argc<<" "<<argv[0];
    //myfile = readdir(dir);
    //cout<<myfile->d_name;
    while((myfile = readdir(dir))!=NULL){
         //cout<<"yo";
         cout<<myfile->d_name<<endl;
    }
    //close_dir(dir);
}

int wc(int argc, char* argv[]){
        ifstream inf;
        int words=0, chars=0, lines=0;
        char buffer[1000];
        for(int i=2;i<argc;i++){
                inf.open(argv[2]);
                while(inf.getline(buffer,1000,'\n')){
                        lines++;
                        int i=0;
                        while(buffer[i]!='\0'){
                                if(buffer[i]==' '){
                                        words++;
                                        while(buffer[i]==' '&&buffer[i]!='\0')
                                                {chars++;i++;}
                                }else {chars++;i++;}
                        }
                        chars++;
                     
                }
                cout<<lines<<" "<<words<<" "<<chars<<" "<<argv[i]<<endl;
        }
}

int kill(int argc, char* argv[]){
    if(argc<3){
        cout<<"PID must be entered";
        return -1;
    }
    int a = kill(atoi(argv[2]),SIGKILL);
    cout<<a;
}


int rm(int argc, char* argv[]){
    if(argc<3){
        cout<<"File name must be entered";
        return -1;
    }
    for(int i=2;i<argc;i++){
    if(unlink(argv[i]) == 0){
        cout<<"Success, file is removed";

    }
    else {cout<<"There is an error while removing the files";
     }
    }
    return 0;
}

int catS(int argc, char* argv[]){
    for(int i=2;i<argc;i++){
        int fd = open(argv[i],O_RDONLY);
        if(fd==-1)break;
        char buff[2];
        while((read(fd,buff,1)>0))cout<<buff[0];
        close(fd);
        }
    return 1;
}

int main(int argc, char* argv[]){
   /*switch(argv[1]){
	case "ls":ls(argc,argv);break;
	case "cat":catS(argc,argv);break;
	case "rm":rm(argc,argv);break;
	case "kill":kill(argc,argv);break;
	case "wc":wc(argc,argv);break;
        default:cout<<"Exit";return 0;
	}*/
        cout<<argv[1];
	if(!strcmp(argv[1],"ls"))ls(argc,argv);
	
}
