#include<iostream>
using namespace std;
struct node{
	int key;
	int num;
};
const int n=3;
const int size=3;
int l;int check=0;
node a[n][size];
int add(node H[],int i,int key,int num,int ni){
	//cout<<i<<" "<<ni<<"  ";
//	int nb=ni;
	if(i<ni){
		H[i].key=key;
		H[i].num=num;
		//cout<<ni<<"  ";
		//int j=i;cout<<" a ";
		while(H[i].key<H[(i-1)/2].key&&i>0){
			node temp=H[i];
			H[i]=H[(i-1)/2];
			H[(i-1)/2]=temp;
			i=(i-1)/2;
			cout<<ni<<" ";
		}
		
		return ni;
	}else{
		//cout<<ni<<" ";
		cout<<" Invalid entry ";
		return ni;
	}
}
void del(node H[],int i){
	int j=0;
	if(i>0){
		//int k=H[i].key;
		H[0]=H[i-1];
		//H[0]=H[n-1];
		while(j<i&&((H[j].key>H[2*j+1].key)||(H[j].key>H[2*j+2].key))){
			//cout<<" a ";
			if((H[j].key>H[2*j+1].key)||(H[j].key>H[2*j+2].key)){
				if(H[2*j+2].key>H[2*j+1].key){
					node temp=H[j];
					H[j]=H[(2*j+1)];
					H[2*j+1]=temp;
					j=2*j+1;	
				}else{
					node temp=H[j];
					H[j]=H[(2*j+2)];
					H[2*j+2]=temp;
					j=2*j+2;	
				}
			}
		}
	}else{
		cout<<" Not possible ";
		return;
	}
}

void make_heap(node H[],int count[]){
	while(check<n*size)
	{
	//cout<<" a ";
	int m=H[0].key;
	int nu=H[0].num;
	cout<<m<<"  ";//<<nu<<"  ";
	check++;
	if(check==n*size){
		cout<<" Finished ";return;
	}
	if(count[nu]>=size){
		del(H,l);l--;
		//cout<<m<<" ";
		int y=0;
		while(count[y]>=size&&y<n){
		//cout<<y;//<<" "<<count[y]<<"  ";
		//cout<<" a ";
		y++;}
		//cout<<y;
		if(y==n)
		{	//cout<<n<<" a ";
		cout<<"Limit reached ";
		return;}else{
			//H[0]=a[y][count[y]++];
			nu=y;}
		//}
	}
	//else
	{
		//if(nu==1)cout<<" a ";
		H[0]=a[nu][count[nu]++];
		int j=0;
		while(j<l&&((H[j].key>H[2*j+2].key)||(H[j].key>H[2*j+1].key))){
			//cout<<" a ";
			if(H[2*j+1].key<H[2*j+2].key){
				if(H[2*j+2].key>H[2*j+1].key){
					node temp=H[j];
					H[j]=H[(2*j+1)];
					H[2*j+1]=temp;
					j=2*j+1;	
				}else{
					node temp=H[j];
					H[j]=H[(2*j+2)];
					H[2*j+2]=temp;
					j=2*j+2;	
				}
			}
		}
	}
	}
}
int main(){
//	cout<<"Enter the number of files and size";
//	cin>>n;
	int d,j=0,i,mn,nl=n,count[nl];
	for(int i=0;i<n;i++){
		//int d;int j=0;
		do{//a[i][j]=new(node);
		cin>>d;
		a[i][j].key=d;
		a[i][j].num=i;
		j++;
		}while(d!=-1&&j<size);	
	}
	node H[n];
	for( i=0;i<n;i++)count[i]=1;
	for(i=0;i<n;i++){
		
		nl=add(H,i,a[i][0].key,a[i][0].num,nl);
	
	}

//	make_heap(H,count);
	//for(int i=0;i<n;i++)cout<<H[i].key<<" ";//<<H[i].num<<" ";
}
