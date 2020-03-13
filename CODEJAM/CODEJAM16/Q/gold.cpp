#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("gold_small.in");
	fin>>Num_Test;
	ofstream fout;
	fout.open("out_small.in");
	for(iter=0;iter<Num_Test;iter++){
		int K,C,S;
		fin>>K>>C>>S;
		int count=0,res[S],temp;
		temp=K;
		if(C==1){
			if(S>=K){
				for(int i=0;i<S;i++)
					res[i]=i+1;
				count=S;
			}
			else
				count=0;
		}
		else{
			if(S>=(K+1)/2){
				while(count<(K+1)/2){
					res[count++]=(K*count)+temp--;
				}
			}
		}
		if(count==0)
			fout<<"CASE #"<<iter+1<<": "<<"IMPOSSIBLE"<<endl;
		else{
			fout<<"CASE #"<<iter+1<<": ";
			for(int i=0;i<count;i++)
				fout<<res[i]<<" ";
			fout<<endl;
		}
	}
	return 0;
}