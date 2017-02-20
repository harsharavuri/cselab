#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct link;
struct node{
	char nn;
	struct link* start;
};
struct link{
	string l;
	struct link* next;
};

struct record{
	char ch[10];
	int lc;
};

node rules[100];
string rc[100][100];
int nt, nn;
int len;
string tobechecked;

string combinations[100];
int comblength=0;
void gencomb(int a, int b){
	comblength=0;	
	for(int i=0;i<a;i++){
		int j = a-i-1;
		for(int k=0;k<rc[i][b].length();k++){
			for(int y=0;y<rc[j][b+i+1].length();j++){
				string toadd = "";
				toadd = toadd + rc[i][b][k]+rc[j][b+i+1][y];
				combinations[comblength++] = toadd;	
			}
		}
	}


}

void checkword(){

	cout<<"Enter the word to be checked";
	cin>>tobechecked;
	len = strlen(tobechecked.c_str());
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			rc[i][j]="";
		}
	}
	for(int i=0;i<len;i++){
		string a = "" + tobechecked[i];
		for(int j=0;j<nn;j++){
			struct link* temp = rules[j].start;
			while(temp!=NULL){
				if(temp->l==a){
					rc[0][i]=rc[0][i]+rules[j].nn;
				}
				temp = temp->next;
			}
		}
	}
		
	for(int i=1;i<len;i++){
		for(int m=0;m<len-i;m++){
			gencomb(i, m);
		
		for(int j=0;j<nn;j++){
			struct link* temp = rules[j].start;
			while(temp!=NULL){
				for(int y=0;y<comblength;y++){
					if(temp->l == combinations[y]){
						rc[i][m]=rc[i][m]+rules[j].nn;
					}
				}
			}
		}
	}

	
}
}


int main(){
	//int nt, nn;
	cout<<"Enter the number of non terminals with start symbol at the beg.";
	cin>>nn;
	//	cin>>ct[i];
	char cn[nn];
	cout<<"Enter the non terminals";
	for(int i=0;i<nn;i++){
		cin>>cn[i];
	}

	//node rules[nn];
	for(int i=0;i<nn;i++){
		rules[i].nn = cn[i];
		string s;
		rules[i].start = NULL;
		struct link* temp = rules[i].start;
		cout<<"Enter -1 at the end of each rule";
		cin>>s;
		if(s!="-1"){
			rules[i].start = new struct link();
			temp = rules[i].start;
			temp->l = s;
			temp->next = NULL;
			cin>>s;
		
		while(s!="-1"){
			temp->next = new struct link();
			temp=temp->next;
			temp->l = s;
			temp->next = NULL;
			cin>>s;
		}}
		//cout<<"\n OUT";
	}
	cout<<"\n The rules are: ";
	for(int i=0;i<nn;i++){
		cout<<rules[i].nn<<" ";
		struct link* temp = rules[i].start;
		while(temp!=NULL){
			cout<<temp->l<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}

	checkword();
	//struct record rc[l][l];
//	for(int i=0;i<l;i++){
//		for(int j=0;j<l;j++){
//			rc[i][j].lc=0;
//		}
//	}
	
	/*
	for(int i=0;i<l;i++){
		
	//}
	int flag=1;
	string addtothis[10];
	int currentlength=0;
	addtothis[0]=tbv[i];
	currentlength++;	
	while(flag==1){
		flag = 0;
		for(int i=0;i<nn;i++){
			struct link* temp = rules[i].start;
			while(temp!=NULL){
				for(int j=0;j<currentlength;j++){
					if(temp->l == addtothis[j]){
						int k;
						for(k=0;k<rc[0][i].lc;k++){
							if(rc[0][i].ch[k]==rules[i].nn){
								break;
							}
						}
						if(k<rc[0][i].lc){
							rc[0][i].ch[rc[0][i].lc++]=rc[0][i];
						}
					}
				}
			}
		}

	}

	}*/

}
