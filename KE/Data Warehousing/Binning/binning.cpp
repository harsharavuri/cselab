#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void binning(int a[][3]){
	ifstream ifs("trans.txt");
	char ch[100];
	int i=0;
	int j =0;
	while(ifs>>ch){
		//ifs>>ch;
		//ifs>>ch;
		int b = atoi(ch);
		a[i][j]=b;
		j++;
		if(j==3){
		i++;j=0;}
	}
	for(int k=0;k<i;k++){
		sort(a[k], a[k]+2);
	}
	
	for(int k=0;k<i;k++){
		int avg=0;
		for(int y=0;y<3;y++){
			avg+=a[k][y];
		}
		avg=avg/3;
		for(int y=0;y<3;y++){
			a[k][y]=avg;
			cout<<a[k][y]<<"  ";
		}
		cout<<endl;
	}
	
	
	/*
	for(int k=0;k<i;k++){
		int avg=0;
		int b1=a[k][0];
		int b2=a[k][2];
		for(int y=1;y<2;y++){
			if((b1-a[k][y])*(b1-a[k][y]) < (b2-a[k][y])*(b2-a[k][y])){
				a[k][y]=b1;
			}else{
				a[k][y]=b2;
			}
			cout<<a[k][y]<<"  ";
		}
		cout<<endl;
	}*/
	
	ofstream ofs("output.txt");
	for(int k=0;k<i;k++){
		for(int y=0;y<3;y++){
			ofs<<a[k][y]<<" ";
		}
		ofs<<endl;
	}
	
	
}

int main(){
	int a[100][3];
	binning(a);
}
