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

void print(node* n){
	while(n!=NULL){
		cout<<n->data<<" --- ";
		n=n->child;
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
		cout<<v[i].size()<<" ";
	}
	print(par);
	
}
