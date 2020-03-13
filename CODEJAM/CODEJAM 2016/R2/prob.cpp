#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("prob.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,K;
		fin>>N>>K;
		float* arr=new float[N];
		for(int i=0;i<N;i++)
			fin>>arr[i];
		sort(arr,arr+N);
		float prob=0,mul=1;
		for(int i=0;i<K/2;i++){
			mul*=(1-arr[i])*(arr[N-1-i]);
		}
		prob+=mul;
		mul=1;
		for(int i=0;i<K/2;i++){
			mul*=(arr[i])*(1-arr[N-1-i]);
		}
		prob+=mul;
		cout<<"CASE	#"<<iter+1<<": "<<prob<<endl;
	}
	return 0;
}