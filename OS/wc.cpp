#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<fstream>
using namespace std;
int main(int argc, char* argv[]){
	ifstream inf;
	int words=0, chars=0, lines=0;
	char buffer[1000]; 
	for(int i=1;i<argc;i++){
		inf.open(argv[i]);
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
			//words++;
		//cout<<lines<<" "<<words<<" "<<chars<<" "<<argv[i]<<endl;
		}
		cout<<lines<<" "<<words<<" "<<chars<<" "<<argv[i]<<endl;  
	}   
}
