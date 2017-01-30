#include<bits/stdc++.h>

using namespace std;
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
	ifstream ifst("records.txt");
	for(int i=0;i<count;i++){
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	int countBeta=0;
	/*while(ifst>>ch){
		if(atoi(ch)>0){
			countBeta++;
		}else{
			
		}
	}*/
	string fname[count];
	ofstream ofs[count];
	for(int i=0;i<count;i++){
		fname[i]="";
		char buff[10];
		fname[i]="items";
		fname[i] = fname[i] + itoa(i,buff, 10);
		fname[i] = fname[i]+".txt"; 
		//ofstream ofs[i];
		ofs[i].open(fname[i].c_str()); 	
	}
	int rowCount=0;
	while(ifst>>ch){
		if(atoi(ch)>0){
			countBeta=0;
			rowCount++;
		}else{
			int check=0;
			ofs[countBeta]<<"T"<<rowCount;
			for(check=0;check<v[countBeta].size() && ch[0]!=v[countBeta][check]; check++);
			for(int i=0;i<v[countBeta].size();i++){
				if(i==check){
					ofs[countBeta]<<" 1";
				}else{
					ofs[countBeta]<<" 0";
				}
			}
			ofs[countBeta]<<"\n";
			countBeta++;
		}
	}
	for(int i=0;i<count;i++){
		ofs[i].close();
	}
	
	//cout<<filesize;
}
