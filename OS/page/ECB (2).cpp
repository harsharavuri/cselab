#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string row_tr(int *arr, int klen, char * pt, int el)
{
        string et = " ";
        for(int i=1;i<=klen;i++)
        {
                int k = 0;
                for(;k<klen && arr[k]!=i;k++ );
                for(;k<el;k=k+klen)
                        et=et+(char)(pt[k]-32);
        }
        return et;
}
int main()
{
        int klen;
        cout<<"Enter the key Length : ";
        cin>>klen;

        int *key = new int[klen];
        cout<<"\nEnter the Key : ";
        for(int i=0;i<klen;i++)
                cin>>key[i];

        string pt;
        getchar();

        cout<<"Enter Plain Text : ";
        getline(cin,pt);
	cout<<"\nEnter the No of Block :";
        int nb; string ct=" ";
        cin>>nb;
        int p=0;
        for(int i=0;i<nb;i++)
        {
                string st = row_tr(key,klen,&pt[i*nb],nb);
                ct=ct+st;
                cout<<st<<endl;
        }


        cout<<"\nCipher TExt : "<<ct<<endl;
}

