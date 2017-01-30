#include<bits/stdc++.h>
using namespace std;




const int in=50;
	

int join(stack<string> & st,int i,  int n){
	char buff[10];
	string I="I";
	if(i==1)for(int j=0;j<n;j++){
		
		st.push(I+itoa(j, buff, 10));
		if(n==1)return 0;
	}
	else{
		if(st.empty())return 0;
		string s[1000];int j=0;
		while(!st.empty()){
			s[j]=st.top();j++;st.pop();
		
		}
		if(j==1)return 0;
	
		for(int k=0;k<j;k++){
			for(int l=k+1;l<j;l++){
			
				if(s[k].substr(0,s[k].length()-1)==s[l].substr(0,s[l].length()-1)){
					st.push(s[k].substr(0,s[k].length()-1)+s[l][s[l].length()-1]+I+s[k][s[k].length()-1]);
					
				}
			}
		}
	
	}
	return 1;
}

int hash(int h[][in]){
	ifstream ifs("invert.txt");
	
	
	while(!ifs.eof()){
		string s;
		getline(ifs, s, '\n');
		int i=0;
		char buff[10];
		if(s[i]=='\0')break;
		while(s[i]!='\0' && s[i]!=' ')i++;
		int num = atoi(s.substr(1,i).c_str());
		if(s[i]=='\0')continue;
		while(s[i]!='\0'){
			int in;
			i++;int j = i+1;
			while(s[i]!='\0' && s[i]!=' ')i++;
			in = atoi(s.substr(j,i).c_str());
			h[num][in]=1;
		}
	}
	
}

void print(stack<string> s){
	while(!s.empty()){
	cout<<s.top()<<" ";s.pop();}
}

int countTrans(stack<string> & s, int h[][in], int n, int minsup, int fcount){
	string fname="";char buff[10];
	fname="countTrans";
	fname = fname + itoa(fcount,buff, 10);
	fname = fname+".txt"; 
	char buffer[10];
	ofstream ofs(fname.c_str());
	stack<string> s2;
	while(!s.empty()){
		string str;
		string I = "I";
		str = s.top();
		s.pop();
		int i=0;int c=0;
		while(str[i]!='\0'){
			if(str[i]=='I')c++;
			i++;
			
		}
		
		int num[c];
		i=0;int j =0;
		while(str[i]!='\0'){
			i++;int k =i;
			while(str[i]!='\0' && str[i]!='I')i++;
			num[j]=atoi(str.substr(k,i).c_str());j++;
		} 
	
		int count=0;
			for(int y=0;y<in;y++){
			
			for(j=0;j<c;j++){
		
				if(h[num[j]][y]==0)break;
				
			}
		
			if(j==c)count++;
		}
			
		
		if(count>minsup){
			string temp="";
			string I ="I";
			for(int i=0;i<c;i++){
				char buff[10];
				temp += I + itoa(num[i],buff,10);
			}
			ofs<<temp;
			s2.push(temp);
			ofs<<" "<<count<<endl;
		
		}
		
	}
	s=s2;
	ofs.close();
}

int main(){
	int trans=10;
	int h[trans][in];
	int minsup=3;
	for(int i=0;i<trans;i++)
		for(int j=0;j<in;j++)
			h[i][j]=0;
		
	int i = 0;
	int n = 10;
	stack<string> s;
	
	hash(h);

	if(join(s, 1, trans))
	{	if(!s.empty())
		countTrans(s,h,trans,minsup, i++);
	}
	while(join(s, 2, trans))
	{
		if(s.empty())break;
		countTrans(s,h,trans,minsup, i++);
	}

}
