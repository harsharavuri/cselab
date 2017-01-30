#include<bits/stdc++.h>
using namespace std;
string str[]={"State/Province","country","City"};
struct node{
	string data;
	struct node* parent;
	struct node* child;
	
};



node* insertNode(node* n, int i){
	if(n==NULL){
		n= new node();
		n->data=str[i];
		n->child=n->parent=NULL;
	}else{
		n->child=insertNode(n->child, i);
		//n->child->parent=new node();
		n->child->parent = n;
	}
	return n;
}

struct specific;

struct specific{
	string data;
	int count=0;
	struct specific* child[10];
	struct specific* parent;
};
int yo=0;



specific* insertSpecific(specific* s, char i[]){
	if(strcmp(i,"") == 0)return s;
	if(strcmp(i,"\0") == 0)return s;
	string data;
	int k=0;
	while(*i!=' ' && *i!='\0'){
		data[k++] = *i++;
	}
	data[k]='\0';
	int j=0;
	for(j=0;j<s->count;j++){
		if(s->child[j]->data == data)break;
	}
	if(j==s->count){
		s->child[s->count]=new specific();
		s->child[s->count]->parent=NULL;
		s->child[s->count]->data=data;
		s->count++;
	}
	while(*i!=' '&& *i!='\0')i++;
	s->child[j] = insertSpecific(s->child[j], i);
	return s;
}

void print(node* n){
	while(n!=NULL){
		cout<<n->data<<" --- ";
		n=n->child;
	}
}


specific* insertSpecificString(specific* s, string i[], int count, int max, int priOrder[]){
	if(count==max)return s;
	//if(strcmp(i,"\0") == 0)return s;
	string data = i[priOrder[count++]];
	//int k=0;
	//while(*i!=' ' && *i!='\0'){
	//	data[k++] = *i++;
	//}
	//data[k]='\0';
	int j=0;
	for(j=0;j<s->count;j++){
		if(s->child[j]->data == data)break;
	}
	if(j==s->count){
		s->child[s->count]=new specific();
		s->child[s->count]->parent=NULL;
		s->child[s->count]->data=data;
		s->count++;
	}
	//while(*i!=' '&& *i!='\0')i++;
	s->child[j] = insertSpecificString(s->child[j], i, count, max, priOrder);
	return s;
}

void printSpec(specific* spec){
	if(spec==NULL)return;
	cout<<spec->data<<" - ";
	if(spec->count==0)return;
	for(int i=0;i<spec->count;i++){
		printSpec(spec->child[i]);
		//cout<<endl;
	}
	
}



int main(){
	ifstream ifs("records.txt");
	vector<char> v[10];
	//vector<char> ch2;
	char ch[10];
	int filesize=0;
	int count=0;int trans;
	
	while(ifs>>ch){
		if(atoi(ch)>0){
			count=0;
			filesize++;
		}else{
			int i;
			for(i=0;i<v[count].size();i++){
				if(v[count][i]==ch[0]){
					break;
				}
			}
			if(i==v[count].size()){
				v[count].push_back(ch[0]);
			}
			count++;
		}
		
	}
	ifs.close();
	int columns[count];
	for(int i=0;i<count;i++)columns[i]=i;
	//cout<<count;
	for(int i=0;i<count;i++){
		for(int j=i+1;j<count;j++){
			if(v[i].size()>v[j].size()){
				vector<char> temp=v[i];
				v[i]=v[j];
				v[j]=temp;
				int t=columns[i];
				columns[i]=columns[j];
				columns[j]=t;
			}
		}
	}
	
	node* par=NULL;
	
	for(int i=0;i<count;i++){
		par = insertNode(par, columns[i]);
		//cout<<v[i].size()<<" ";
	}
	//print(par);
	
	ifs.close();
	ifstream ifst("records.txt");
	specific* spec = new specific();
	spec->data="start";
	string str[10];
	string s;
	while(getline(ifst,s,'\n')){
		int count=0;
		int i=0;
		while(s[i]!=' ')i++;
		while(s[i]==' ')i++;
			
		while(s[i]!='\0'){
			string temp;int j=0;
			while(s[i]!='\0' && s[i]!=' '){
				//cout<<s[i]<<" ";
				//cout<<"yo ";
				temp=temp+s[i++];
				//cout<<temp[j-1]<<"-";
			}
			//cout<<temp[j-1]<<"- ";
			//temp[j]='\0';
			//cout<<temp<<" ";
			str[count++]=temp;
			while(s[i]==' '&& s[i]!='\0')i++;
		}
		//for(int i=0;i<count;i++)cout<<str[i]<<" - ";
		spec = insertSpecificString(spec, str, 0, count, columns);
		//cout<<count<<" ";	
		//string tmep = strtok(s);
	}
	printSpec(spec);
	
	
}
