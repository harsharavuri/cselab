#include<iostream>
#include <string>
#include <cstdio>
using namespace std;

string row_transpos(int *arr,int klen,char* pt,int el){
        string et="";
        for(int i=1;i<=klen;i++){
                int k=0;
                for(;k<klen&&arr[k]!=i;k++);
                for(;k<el;k=k+klen)
                        et=et+((char)(pt[k]-32));
        }
        return et;
}

int main(){
        int klen;
        cout<<"Enter the key lenght: ";
        cin>>klen;
        int *key=new int[klen];
        cout<<"Enter the key: ";
        for(int i=0;i<klen;i++)
                cin>>key[i];
        string pt;
        getchar();
        cout<<"Enter the plaintext: ";
        getline(cin,pt);
        int n;
        cout<<"Enter the no. of block in which you want to divide: ";
        cin>>n;
        string ct="";
        int p=0;
        string iv="00000";
        for(int i=0;i<n;i++){
                for(int j=i*n;j<n;j++)
                        pt[j]=pt[j]^iv[j];
                string st=row_transpos(key,klen,&pt[i*n],n);
                ct=ct+st;
                cout<<st<<endl;
                iv=st;
        }
        cout<<"Encrypted text: "<<ct<<endl; }
                                                  
