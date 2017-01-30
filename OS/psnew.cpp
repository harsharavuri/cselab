#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]){

	DIR* dir = opendir("/proc");
	if(dir!=NULL){
	 struct dirent* temp;
	 while((temp = readdir(dir))!=NULL){
	   if(atoi(temp->d_name)!=0){
		char buff[100];
		strcpy(buff, "/proc/");
		strcat(buff, temp->d_name);
		if(opendir(buff)!=NULL){
			strcat(buff,"/status");
			ifstream ifs(buff);
			string s;
			string name,status,tgid,pid;
			ifs>>s;ifs>>s;name=s;
			ifs>>s;ifs>>s;status=s;ifs>>s;
			ifs>>s;ifs>>s;tgid=s;
			ifs>>s;ifs>>s;pid=s;
			if(status=="R"){cout<<name<<" "<<status<<" ";
			cout<<tgid<<" "<<pid;
			//ifs>>s;cout<<s<<" ";	
			cout<<endl;}
		}
		}	
	}
	}

}
