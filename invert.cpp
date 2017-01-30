#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream ifs("trans.txt");
	ofstream ofs("invert.txt");
	string s;
	int trans = 10;
	stack<int> st[trans];
	if(!ifs.eof())
	ifs>>s;
	while(!ifs.eof()){
		if(s[0]=='\0')break;
		int num = atoi(s.substr(1).c_str());
		ifs>>s;
		while(!ifs.eof() && s[0]!='T' && s[0]!='\0'){
			st[atoi(s.substr(1).c_str())].push(num);
			ifs>>s;
		
		}
	}
	for(int i=0;i<trans;i++){
		ofs<<"I"<<i;
		while(!st[i].empty()){
			int top = st[i].top();
			st[i].pop();
			ofs<<" T"<<top;
		}
		ofs<<endl;
	}	
}
