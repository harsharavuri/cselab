#include<bits/stdc++.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<iostream>
using namespace std;
int main(int argc, char* argv[]){
    DIR* dir;
    //struct stat mystat;
    struct dirent* myfile;
    dir = opendir(argv[1]);
    cout<<argc<<" "<<argv[1];
    //myfile = readdir(dir);
    //cout<<myfile->d_name;
    while((myfile = readdir(dir))!=NULL){
         //cout<<"yo";
         cout<<myfile->d_name<<endl;
    }
    //close_dir(dir);
}
