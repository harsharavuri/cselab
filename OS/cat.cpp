#include<iostream>
#include<fstream>
//#include<sys/dirent.h>
//#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
//#include<unistd.h>
using namespace std;
int main(int argc, char* argv[]){
    //DIR* dir;
    ifstream inf;
    char buff[1000];
    //struct dirent* myfile;
    for(int i=1;i<argc;i++){
        inf.open(argv[i]);
        while(inf.getline(buff,1000,'\n'))
        {
            cout<<buff<<endl;
        }
        inf.close();
    }
}
