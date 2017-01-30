#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int getAvg(int a[],int size, int med[]){
	fstream ifs("trans.txt");
	int am[100]={0};int bm[100]={0};int cm[100]={0};
	char ch[10];
	int count1=0;
	int count2=0;
	int count=0;
	while(ifs>>ch){
		ifs>>ch;
		//cout<<ifs.tellg()<<"  ";
		{
			int k = atoi(ch);
			ifs>>ch;
			//cout<<ifs.tellp()<<"  ";
			int y = atoi(ch);
			if(k==0 && y!=0){
				a[0]=a[0]+y;
				am[count1]=y;
				count1++;
				cm[count++]=y;
				
			}else if(y!=0){
				a[1]=a[1]+y;
				bm[count2]=y;
				count2++;
				cm[count++]=y;
			}
			a[2]=a[2]+y;
		}
	}
	
	//cout<<count1<<"  "<<count2<<"   ";
	a[0]=a[0]/count1;
	a[1]=a[1]/count2;
	a[2]=a[2]/(count1+count2);
	count1--;count2--;count--;
	
	if(count1%2==0){
		med[0]=am[count1/2];
		//cout<<med[0];
	}else{
		med[0]=am[(count1/2 + (count1+1)/2)/2];
	}
	
	if(count2%2==0){
		med[1]=bm[count2/2];
	}else{
		med[1]=bm[(count2/2 + (count2+1)/2)/2];
	}
	
	if(count%2==0){
		med[2]=cm[count/2];
		//cout<<count;
	}else{
	//	cout<<count;
		med[2]=cm[(count/2 + (count+1)/2)/2];
	}
	
	cout<<med[0]<<"  "<<med[1]<<"  "<<med[2];
	ifs.close();
}

int fillMissingValues(int a[], int size){
	fstream fs("trans.txt");
	ofstream ofs("output.txt");
	char ch[10];char c[10];
	while(fs>>ch){
		ofs<<ch<<" ";
		
		fs>>ch;
		ofs<<ch<<" ";
			int k = atoi(ch);
			//int yo = fs.tellg();
			//cout<<yo<<"  ";
			fs>>ch;
			int y = atoi(ch);
			//cout<<y<<"  ";
			if(y==0){
			/*	if(k==0){
					ofs<<a[0]<<"\n";
				}else{
					ofs<<a[1]<<"\n";
				}*/
				ofs<<a[2]<<"\n";
			}else{
				ofs<<ch<<"\n";
			}
		
	}
	ofs.close();fs.close();
}

void copyback(){
	ofstream ofs("trans.txt");
	ifstream ifs("output.txt");
	string s;
	while(getline(ifs, s, '\n')){
		ofs<<s<<"\n";
	}
}

int main(){
	// avg[2] signifies overall average, 0 signifies average of safe people, 1 signifies average of risky people 
	int a[3]={0};
	int med[3]={0};
	getAvg(a,3,med);
	fillMissingValues(med,3);
	copyback();
	//cout<<a[0]<<"  "<<a[1]<<"  "<<a[2]<<"  ";//<<count1<<"   "<<count2;
}
