#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
#include<iostream>
using namespace std;
int main(int argc, char* argv[]){
    if(argc<2){
        cout<<"PID must be entered";
        return -1;
    }
    int a = kill(atoi(argv[1]),SIGKILL);
    cout<<a;
}
