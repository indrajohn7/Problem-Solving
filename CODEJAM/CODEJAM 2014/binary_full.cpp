#include<bits/stdc++.h>
#define Max 1000

using namespace std;

vector<int> E[Max];
vector<int> F[Max];
int main()
{
	int Num_Test,iter,count=0;
	ifstream fin;
	fin.open("binary.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,i,j,a,b;
		fin>>N;
		for(i=1;i<N;i++){
			fin>>a>>b;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		F=E;
		int arr[N];
		j=0;
		for(i=1;i<=N;i++){
			if(F[i].size()==2)
				 arr[j++]=i;
				count++;			 
		}
		a=0;	
		while(count--){
			
		}
		
	}
}