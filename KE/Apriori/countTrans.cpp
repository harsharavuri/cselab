#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream ifs("invert.txt");
	ofstream ofs("countTrans.txt");
	string s;
	while(!ifs.eof()){
		//cout<<"oy";
		getline(ifs, s, '\n');
		int count=0,i=0;
		if(s[i]=='\0')break;
		//ofs<<"{";
		while(s[i]!='\0' && s[i]!=' '){
			ofs<<s[i];i++;
		}
		ofs<<" ";
		while(s[i]!='\0'){
			if(s[i]==' ')count++;
			i++;
		}
		ofs<<count<<endl;
	}
	ofs.close();
	ifs.close();
}
