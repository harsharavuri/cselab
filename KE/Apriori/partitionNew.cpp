#include<bits/stdc++.h>
using namespace std;

// IMPORTANT
/*

	Note that in stands for the number of transactions and trans stands for number of I's

*/


const int in=15;
	

void print(stack<string> s){
	while(!s.empty()){
	cout<<s.top()<<" ";s.pop();}
}


/*int prune(stack<string> &tes,stack<string> & stak, string s[], int j){
	while(!stak.empty()){
		string st = stak.top();
		int k=1;
		while(st[k]!='I' && st[k]!='\0'){
			k++;
		}
		if(st[k]=='\0')return 0;
		string tempstr=st;
		st = st.substr(k, st.length());
		stak.pop();int i=0;
		for(i=0;i<j;i++){
			if(s[i]==st)break;
		}
		if(i<j)tes.push(tempstr);
	}
	stak=tes;
	//print(tes);
	cout<<"yo";*/
	
int prune(string tempstr, string s[], int j)
{
	int i=0;
	if(tempstr[i]=='\0')return 1;
	for(i=0;i<j;i++){
		if(tempstr==s[i])break;
	}
	if(i<j)return 1;
	return 0;
}	




int join(stack<string> & st,int i,  int n){
	char buff[10];
	string I="I";
	stack<string> tes;
	if(i==1)for(int j=0;j<n;j++){
		
		st.push(I+itoa(j, buff, 10));
		if(n==1)return 0;
	}
	else{
		if(st.empty())return 0;
		string s[1000];int j=0;
		while(!st.empty()){
			s[j]=st.top();j++;st.pop();
			//cout<<s[j-1];
		}
		if(j==1)return 0;
		//cout<<j;
		for(int k=0;k<j;k++){
			for(int l=k+1;l<j;l++){
				//cout<<s[l].substr(0,s[l].length()-1);
				if(s[k].substr(0,s[k].length()-1)==s[l].substr(0,s[l].length()-1)){
					string tempstr = s[k].substr(0,s[k].length()-1)+s[l][s[l].length()-1]+I+s[k][s[k].length()-1];
					string temppass; int tempi=1;
					temppass = tempstr;
					while(tempstr[tempi]!='I' && tempstr[tempi]!='\0')tempi++;
					temppass = temppass.substr(tempi, temppass.length());
					int checkPrune = prune(temppass, s, j);
					//cout<<checkPrune<<"  ";
					if(checkPrune){
					st.push(tempstr);
					
					//cout<<tempstr<<endl;
					}else{}//tes.push(st.top());
					//cout<<s[k].substr(0,s[k].length()-1)+s[l][s[l].length()-1]+I+s[k][s[k].length()-1]<<endl;;
				}
			}
		}
		
		//cout<<st.top()<<"  ";
		//prune(tes,st, s, j);
	
	}
	return 1;
}


int hashBasedOptimization(stack<string>& s, int h[][in], int minsup){
	int bucketCount[7]={0};
	stack<string> sta[7];
	stack<string> s2;
		{
	
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
		//cout<<c<<"--c--";
	
		//cout<<num[i]<<" ";
		int count=0;
			for(int y=0;y<in;y++){
			
			for(j=0;j<c;j++){
			//	cout<<h[num[j]][y]<<" ";
				if(h[num[j]][y]==0)break;
				
			}
			//cout<<endl;
			if(j==c)count++;
		}
		
		int x; int y;
			int first=1,second;
			
			while(str[first]!='\0' && str[first]!='I')first++;
			int store=first;
			first++;second=first;
			while(str[second]!='\0' && str[second]!='I')second++;
			//cout<<"yo ";
			x = atoi(str.substr(1,store).c_str());
			//cout<<str;
			//cout<<"yo";
			y = atoi(str.substr(first,second).c_str());
			//cout<<"yo ";
			int hashValue = x*10+y;
			hashValue = hashValue%7;
			if(count>minsup){
				sta[hashValue].push(str);
				bucketCount[hashValue]+=count;
			}	
		
		
	}
	
	
		for(int i=0;i<7;i++){
			if(bucketCount[i]>minsup){
				while(!sta[i].empty()){
					s2.push(sta[i].top());
					//ofs<<
					//cout<<sta[i].top()<<"  ";
					sta[i].pop();
				}
			}
		}
		s=s2;
	//	while(!s2.empty())s2.pop();
	
	}
	
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



int countTrans(stack<string> s, int h[][in], int p1, int p2, int minsup,string strElements[], int currentElements[], int& currentSize, int fcount){
	string fname="";char buff[10];
	//fname="countTrans";
	//fname = fname + itoa(fcount,buff, 10);
	//fname = fname+".txt"; 
	char buffer[10];
	//ofstream ofs(fname.c_str());
	stack<string> s2;
	
	//stack<string> s3 = s;
	//if(fcount==1)
	//hashBasedOptimization(s, h, minsup);
	
	//cout<<s.top()<<"  "<<s.empty()<<endl;
	//cout<<"dsa";
	while(!s.empty()){
		//cout<<s.top()<<endl;
		//cout<<s.top()<<"  ";
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
		//cout<<"yo 1";
		while(str[i]!='\0'){
			i++;int k =i;
			while(str[i]!='\0' && str[i]!='I')i++;
			num[j]=atoi(str.substr(k,i).c_str());j++;
		} 
		//cout<<c<<"--c--";
	
		//cout<<num[i]<<" ";
		int count=0;
		//cout<<"yo 1"<<p1<<" "<<p2<<"  ";
			for(int y=p1;y<p2;y++)
			{
			//cout<<"yo 2";
			for(j=0;j<c;j++){
			//	cout<<h[num[j]][y]<<" ";
				if(h[num[j]][y]==0)break;
				
			}
			//cout<<endl;
			if(j==c)count++;
		}
			
		//cout<<str<<"  "<<fcount<<endl;
		if(count>minsup){
			string temp="";
			string I ="I";
			for(int i=0;i<c;i++){
				char buff[10];
				temp += I + itoa(num[i],buff,10);
			}
			//cout<<temp<<"  ";
			int yk=0;
			for(yk=0;yk<currentSize;yk++){
				if(strElements[yk]==temp){
					currentElements[yk]=currentElements[yk]+count;
					break;
				}
				
				//cout<<currentSize<<"  ";
			}
			if(yk==currentSize){
					currentElements[yk]=count;
					strElements[yk]=temp;
					currentSize++;
				}
			//ofs<<temp;
			//s2.push(temp);
			//ofs<<" "<<count<<endl;
			//cout<<" "<<count<<endl;
		}
		
	}
	
	//s=s2;
	//ofs.close();
}

int main(){
	int trans=15;
	int h[trans][in];
	int minsup=2;
	for(int i=0;i<trans;i++)
		for(int j=0;j<in;j++)
			h[i][j]=0;
		
	int i = 0;
	int n = 10;
	stack<string> s;
	
	hash(h);
	
	int internalminsup = minsup/2; //partition
	
	
	/*for(int i=0;i<in;i++){
		cout<<endl;
		for(int j=0;j<trans;j++){
			cout<<h[i][j]<<" ";	
		}
	}*/
	if(join(s, 1, trans))
	{	
		string strElements[100];
		int currentSize=0;
		int currentElements[100]={0};
		//cout<<"yo";
		if(!s.empty()){
		
		//cout<<i<<endl;
		int size=0;
		//stack<string> stemp;
		/*stack<string> stemp1 =s;
		while(!stemp1.empty()){
			stemp1.pop();
			size++;
		}*/
		//int sup = in/2;
		for(int k=0;k<2;k++){	//partition
			/*stack<string> stemp;
			int stacksize=size/2;		//partition;
			for(int y=0;y<stacksize && !s.empty();y++){
				stemp.push(s.top());
				s.pop();
			}
			if(k==1){		// partition-1
				while(!s.empty()){
					stemp.push(s.top());
					s.pop();
				}
			}*/
			int par1=(in/2)*k;		  // partition;
			int par2 = (in/2)*(k+1);	 // partition;
			if(k==1)par2=in;		//partition;
			//cout<<"yo0";
			countTrans(s,h,par1,par2,0,strElements, currentElements, currentSize, i);
			//countTrans(stemp,h,trans,internalminsup,strElements, currentElements, currentSize, i);
			
		}
		//cout<<"yo1";
		char buff[10];
		string fname="countTrans";
		fname = fname + itoa(i++,buff, 10);
		fname = fname+".txt"; 
		ofstream ofs(fname.c_str());
		while(!s.empty())s.pop();

		//cout<<currentSize<<"  ";
		for(int k=0;k<currentSize;k++){
			if(currentElements[k]>minsup){
				s.push(strElements[k]);
				ofs<<strElements[k]<<" "<<currentElements[k]<<endl;
				}
			}
		}
	}
	//cout<<i<<endl;
	while(join(s, 2, trans))
	{	//cout<<"yo2";
		string strElements[100];
		int currentSize=0;
		int currentElements[100]={0};
		//cout<<"yo";
		if(s.empty())break;
		//cout<<i<<endl;
		int size=0;
		//stack<string> stemp;
		/*stack<string> stemp1 =s;
		while(!stemp1.empty()){
			stemp1.pop();
			size++;
		}*/
		//int sup = in/2;
		for(int k=0;k<2;k++){	//partition
			//stack<string> stemp;
			//int stacksize=size/2;		//partition;
			/*for(int y=0;y<stacksize && !s.empty();y++){
				stemp.push(s.top());
				s.pop();
			}
			if(k==1){		// partition-1
				while(!s.empty()){
					stemp.push(s.top());
					s.pop();
				}
			}*/
			int par1=(in/2)*k;		  // partition;
			int par2 = (in/2)*(k+1);	 // partition;
			if(k==1)par2=in;		//partition;
			
			//cout<<"lol2 "<<par1<<"  "<<par2;
			countTrans(s,h,par1,par2,0,strElements, currentElements, currentSize, i);
			//cout<<"lol1 ";
		}
		//cout<<"yo2";
		char buff[10];
		string fname="countTrans";
		fname = fname + itoa(i++,buff, 10);
		fname = fname+".txt"; 
		ofstream ofs(fname.c_str());
		while(!s.empty())s.pop();
		for(int k=0;k<currentSize;k++){
			if(currentElements[k]>minsup){
				s.push(strElements[k]);
				ofs<<strElements[k]<<" "<<currentElements[k]<<endl;
			}
		}

		
	}

}
