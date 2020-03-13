#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_test;
	ifstream fin;
	fin.open("stall.in");
	fin>>Num_test;
	for(iter=0;iter<Num_test;iter++){
		int N,R,O,Y,G,B,V;
		fin>>N; //>>R>>O>>Y>>G>>B>>V;
		int arr[6];
		char barr[6]={'R','O','Y','G','B','V'};
		for(int i=0;i<6;i++){
			fin>>arr[i];
		}
		typedef pair<char,char> pcc;
		vector<pcc> v;
		while(v.size()!=N){
			if(v.size()!=N-1){
				
			}else{
				
			}
		}
	}
}