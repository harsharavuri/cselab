#include<iostream>
using namespace std;
int *a;
void initialise(int size){
	for(int k=0;k<size;k++)
	{
	a[k]=-1;
	}
}
struct node{
	int d1;
	int d2;
	int weight;
};
void sort(node a[],int size){
	for(int i=0;i<size;i++){
		int min=a[i].weight;
		for(int j=i+1;j<size;j++){
			if(a[j].weight<min){
				node temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
}


void add(node H[],int n,int i,node k){
	if(i<=n){ H[i]=k;
		while(H[i].weight<H[i/2].weight&&i>0){ //(i-1)/2
			node temp=H[i];
			H[i]=H[i/2];//(i-1)/2
			H[i/2]=temp;//(i-1)/2
			i=i/2;//(i-1)/2
		}
	}else
	return;
}
node del(node H[],int n){
	int i=1;node k= H[i];
	if(n>0){	
			H[i]=H[n];
			while(2*i<=n&&(H[i].weight>H[2*i].weight||H[i].weight>H[2*i+1].weight)){ //2*i+1   2*i+2
					//cout<<" a ";
					if(2*i>=n||(H[2*i].weight<H[2*i+1].weight))	//2*i+1   2*i+2
					{
					if(H[i].weight>H[2*i].weight)	//2*i+1   2*i+2
					{
					node temp=H[i];
					H[i]=H[2*i];	//2*i+1   2*i+2	
					H[2*i]=temp;	//2*i+1   2*i+2
					//i=2*i;
					}i=2*i;			//2*i+1   2*i+2
				}
				else if(2*i<=n){	//2*i+1   2*i+2
					
					node temp=H[i];
					H[i]=H[2*i+1];	//2*i+1   2*i+2
					H[2*i+1]=temp;	//2*i+1   2*i+2
					i=2*i+1;		//2*i+1   2*i+2
					
			}
	}
		return k;	
	}else{
		//cout<<" 1a ";
		node l;l.d1=-1;l.d2=-1;l.weight=-1;
		return l;
	}
}
void print(int H[],int n){
	for(int i=1;i<=n;i++)
	cout<<H[i]<<" ";
}
int find(int i){
	if(a[i]==-1)return i;
	a[i]=find(a[i]);
}
void union_disjoint(int i,int j){
	if(a[j]==-1){
		a[j]=i;
		//a[i]--;
	}
	else if(a[i]==-1){
		a[i]=j;
		//a[j]--;
	}else{
		//cout<<" c ";//cout<<a[i]<<" ";
			union_disjoint(find(a[j]),find(a[i]));
		}
		//cout<<" c ";
}
int reached(int n){
	int i=0;int check=a[i];
	//if(a[i]<0)return 1;
	for(int j=0;j<n;j++){
	if(a[j]<0)i++;
	}
	if(i==1)return 0;
	return 1;
}
int main(){
	cout<<"Enter the number of vertices ";
	int n;
	cin>>n;
	a=new int[n];
	initialise(n);
	int g[n][n];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
	g[i][j]=0;}
	cout<<" Enter the edge vertices and the corresponding weight ";
	//int b[]={1 ,2 ,2 ,1 ,4 ,1 ,2 ,4 ,3 ,2 ,5 ,10 ,3 ,1 ,4 ,3 ,6 ,5 ,4 ,3 ,2 ,4 ,6 ,8 ,4 ,7 ,4 ,4 ,5 ,2, 5, 7 ,6 ,7, 6, 1};
	int i,j,c,s;
	do{
		cin>>i>>j;
		i--;j--;
		int weight;
		cin>>weight;
		if(i!=-1&&j!=-1&&i<n&&j<n){
			g[i][j]=weight;
		}
	}while(i>=0&&j>=0&&i<=n&&j<=n);
	int k=0;
	//node* H;
	//1 2 2 1 4 1 2 4 3 2 5 10 3 1 4 3 6 5 4 3 2 4 6 8 4 7 4 4 5 7 5 7 6 7 6 1
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(g[i][j]!=0)k++;
		}
	}
	int l=0;
	node h[k];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(g[i][j]!=0){
				h[l].d1=i;
				h[l].d2=j;
				h[l].weight=g[i][j];
				l++;
			};
		}
	}
	//for(int i=0;i<k;i++)cout<<h[i].weight<<"  ";
	cout<<endl;
	//sort(h,k);
	for(int i=0;i<k;i++){
		int max=h[i].weight;
		for(int j=0;j<k;j++){
			if(h[j].weight>max){
				node temp=h[j];
				h[j]=h[i];
				h[i]=temp;
			}
		}
	}
	node H[k];
	for(int i=0;i<k;i++){
		add(H,k,i,h[i]);		
	}
	int chec=k;
	//for(int i=0;i<k;i++)cout<<H[i].weight<<"  "<<H[i].d1<<"  "<<H[i].d2<<"  ";
	cout<<endl;
	node temp=H[0];
	union_disjoint(temp.d1,temp.d2);
	//cout<<temp.d1<<" "<<temp.d2<<" ";
	cout<<temp.weight<<"  ";
	for(int i=0;i<chec-1;i++){
		//cout<<" a ";
		node temp =del(H,k);
		//cout<<" a ";
		k--;
		if((find(temp.d1)!=find(temp.d2))||(find(temp.d1)==-1 && find(temp.d2)==-1)){
			union_disjoint(temp.d1,temp.d2);
			//cout<<temp.d1<<" "<<temp.d2<<" ";
			cout<<temp.weight<<" ";
		} 	
	}
}
