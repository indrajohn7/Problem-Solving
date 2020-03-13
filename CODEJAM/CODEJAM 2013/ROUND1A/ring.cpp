#include<bits/stdc++.h>

#define block pow(10,9)

using namespace std;

int main()
{
	int iter, Num_Test;
	ifstream fin;
	fin.open("ring.in");
	ofstream fout;
	fout.open("a1.out");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		unsigned long long r,t,i=0,j,k,count=0,blocks=0;
		fin>>r>>t;
		float pi=(float)(22/7);
		unsigned long long  area=0,remain;
		
		while(area<(t*pi)){
			area+=pi*(((r+(2*i+1))*(r+(2*i+1)))-((r+2*i)*(r+2*i)));
			i++;
		}
		if(area>(t*pi))
			--i;
		fout<<"Case #"<<iter+1<<": "<<i<<endl;
		cout<<"CASE #"<<iter+1<<": "<<i<<endl;
	}
	return 0;
}