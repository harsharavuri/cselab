#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdio>
#include<stdlib.h>
using namespace std;
const int p=3;
void sort(int a[],int y,int k){
	for(int i=y;i<k;i++){
		for(int j=i;j<k;j++){
			if(a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

void simple_partiton_generator(fstream & outinf,int a[],int length){
	int i;
	for(i=0;i+p<length;){
		sort(a,i,i+p);i=i+3;
	}
	if(i<length)
	sort(a,i,length-1);
	for(int i=0;i<length;i++){
		outinf<<a[i];
		if((i+1)%3 == 0)outinf<<"\n";
		else outinf<<" ";
	}
}
void replace_selection_partition_generator(fstream & outinf,int a[],int length){
	int b[4];
	int i=0;
	while(i<length){
		cout<<" c ";
		int j;
		for(j=0;j<4&&i<length;j++,i++)b[j]=a[i];
		cout<<" d ";
		int flag=1;
	if(j<4){
		sort(b,0,j);
		for(int k=0;k<j;k++)outinf<<b[k]<<" ";
		//cout<<" e ";
		return;
	}else{
		while(flag){
			if(i==length){
				flag=0;
				sort(b,0,4);
				for(int j=0;j<4;j++){
				//cout<<b[j]<<" ";
				outinf<<b[j]<<" ";
				}
				return;			
			}
		int min=b[0];int k=0;
		for(int j=1;j<4;j++){
			if(min>b[j]){
				min=b[j];
				k=j;
				}
			}
			//cout<<" b ";
			outinf<<min<<" ";
			if(a[i]<min){
			/*	if(i==length-1){
					b[4]=a[i++];
					b[k]=1000;
					sort(b,0,5);
					for(int j=0;j<4;j++)outinf<<b[j]<<" ";
					flag=0;
					continue;
				}*/
			b[k]=1000;
			sort(b,0,4);
			for(int j=0;j<3;j++)outinf<<b[j]<<" ";
			flag=0;
			}
			else
			b[k]=a[i++];
		
			}
				//cout<<" a ";
				outinf<<"\n";
		}
	}
}
int main(){
	ofstream outf("final.txt");
	outf.close(); 
	fstream outinf("final.txt",ios::in|ios::out|ios::binary);
	int a[]={3,1,2,5,8,4,0,7,74,12,13,14,15,16,20,51,19,35,17,18,21,76,67,89,98};
	//simple_partiton_generator(outinf,a,11);
	//	int b[100],c[100],d[100],e[100];
	ofstream of("first.txt");
	//of.close();
	ofstream of2("second.txt");
	//of2.close();
	
	ofstream of3("third.txt");
	of3.close();
	ofstream of4("fourth.txt");
	of4.close();
	/*fstream f3("third.txt");
	fstream f4("fourth.txt");*/
	replace_selection_partition_generator(outinf,a,25);
	outinf.seekg(0);
	char ac[100];
	int m=0;
	//cout<<" f ";
	while(!outinf.eof()){
		if(m%2==0){
			outinf.getline(ac,90,'\n');
			of<<ac;
			of<<"\n";
		}else{
			outinf.getline(ac,90,'\n');
			of2<<ac;
			of2<<"\n";
		}
		m++;
	}
	//cout<<" g ";
	of.close();
	of2.close();
	//f1.seekg(0);
	//f2.seekg(0);
	m=0;
	int i=0;int j=0;char ch[2];int al[50];int bl[50];int b=0;
	ch[1]='\0';
	int count=0;
	int g=0;
	while(count!=1){
		count=0;
		//cout<<" a ";
		//cout<<" l ";
		if(m%2==0){
		i=0;
		cout<<" laa ";
		fstream f1("first.txt");
		fstream f2("second.txt");
		ofstream f3("third.txt");
		ofstream f4("fourth.txt");
		
		int l=0;char buffer[100];
		{
			/*while(!f1.eof()){
			l++;
		//	cout<<" b ";
			f1.getline(buffer,100,'\n');
		}
		if(l==1)break;
		
		f1.seekg(0);l=0;
		while(!f2.eof()){
			l++;
			//cout<<"  a  ";
			f2.getline(buffer,100,'\n');
		}
		if(l==1)break;
	
		f2.seekg(0);*/
		}
		//int count=0;
		while(!f1.eof()&&!f2.eof()){
			i=0;
		if(!f1.eof()){
		f1.get(ch[0]);
		while(ch[0]!='\n'&&!f1.eof()){
			al[i]=0;
			
			while(ch[0]!=' '&&ch[0]!='\n'&&!f1.eof()){
				al[i]=al[i]*10+atoi(ch);
				f1.get(ch[0]);
				//cout<<" a ";
			}
			if(ch[0]==' ')
			f1.get(ch[0]);
			//cout<<"  a   ";
			//cout<<al[i]<<" a ";
			//cout<<ch[0]<<"  ";
			i++;
		}
		
		}

		if(!f2.eof()){
		f2.get(ch[0]);
		while(ch[0]!='\n'&&!f2.eof()){
			al[i]=0;
			while(ch[0]!=' '&&ch[0]!='\n'&&!f2.eof()){
				al[i]=al[i]*10+atoi(ch);
				f2.get(ch[0]);
			}
			if(ch[0]==' ')f2.get(ch[0]);
			//cout<<al[i]<<" a ";
			i++;
		}
		}
				//cout<<" b "<<i<<" b ";
		//cout<<" a ";
		sort(al,0,i);
		
		if(b%2==0){
			int z=0;//cout<<"  koo ";
		for(int k=0;k<i;k++){
		//cout<<al[k]<<" a ";
		z=1;
		f3<<al[k]<<" ";
		//cout<<al[k]<<" ";
		//f3<<"\n";
		}
		cout<<endl;		//cout<<" b "<<i<<" b ";
		f3<<"\n";
		if(z)count++;
		}
		else{
			int z=0;
			//cout<<" sadka s ";
		for(int k=0;k<i;k++){
		//	cout<<al[k]<<" ";
		f4<<al[k]<<" ";z=1;
		//f4<<"\n";
		}
		f4<<"\n";
		if(z)count++;
		}
		b++;
		}
		m++;
	}else if(m%2==1){
		//break;
		cout<<" laa ";
		i=0;
		fstream f3("third.txt");
		//f3.seekg(0);
		
		fstream f4("fourth.txt");
		//f4.seekg(0);
		ofstream f1("first.txt");
		ofstream f2("second.txt");
		int l=0;char buffer[100];
	/*	while(!f3.eof()){
			l++;
			//cout<<" a ";
			f3.getline(buffer,100,'\n');
		}
		if(l==1)break;
	
		f3.seekg(0);l=0;
		while(!f4.eof()){
			l++;
			f4.getline(buffer,100,'\n');
		}
		if(l==1)break;

		f4.seekg(0);*/
		//count=0;
		while(!f3.eof()&&!f4.eof()){
			//cout<<" moo ";
			i=0;
		if(!f3.eof()){
		f3.get(ch[0]);
		//cout<<" moo "<<ch[0];
		while(ch[0]!='\n'&&!f3.eof()){
			al[i]=0;
			while(ch[0]!=' '&&ch[0]!='\n'&&!f3.eof()){
				al[i]=al[i]*10+atoi(ch);
				f3.get(ch[0]);
				//cout<<" moo ";
			}
			if(ch[0]==' ')
			f3.get(ch[0]);
			//cout<<al[i]<<" a ";
			//cout<<ch[0]<<"  ";
			i++;
		}
		
		}
		//cout<<i<<" ";
		if(!f4.eof()){
		f4.get(ch[0]);
		while(ch[0]!='\n'&&!f4.eof()){
			al[i]=0;
			while(ch[0]!=' '&&ch[0]!='\n'&&!f4.eof()){
				al[i]=al[i]*10+atoi(ch);
				f4.get(ch[0]);
			}
			if(ch[0]==' ')f4.get(ch[0]);
			//cout<<al[i]<<" a ";
			i++;
		}
		}
			//cout<<i<<" a ";
			sort(al,0,i);
		
			if(b%2==0){
				int z=0;
			for(int k=0;k<i;k++){
				z=1;
			//cout<<" a  asaa ";
			f1<<al[k]<<" ";
			//cout<<al[k]<<" ";
			//f3<<"\n";
			}
			//cout<<" asa ";
			f1<<"\n";if(z)count++;
			}
			else{
				int z=0;
				//cout<<" asa ";
			for(int k=0;k<i;k++){
				z=1;
			//cout<<al[k]<<" a  asaa ";
			f2<<al[k]<<" ";
			//cout<<al[k]<<" ";
			//f4<<"\n";
			}
			f2<<"\n";if(z)count++;
			}
			b++;
			}
			m++;
			//break;
		}
		g++;
	}
	cout<<count<<" ";
}
