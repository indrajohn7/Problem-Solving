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
		unsigned long long  area=0,remain,flag=0;
		remain=t*pi;
		if(r<pow(10,9)){
			if((t*pi)>block){
			flag=1;
			blocks=(t*pi)/block;
			remain=(t*pi)-(blocks*block);
		 }
		}
		if(flag==1){
			while(area<block){
				area+=pi*(((r+(2*count+1))*(r+(2*count+1)))-((r+2*count)*(r+2*count)));
			    count++;
			}			
			if(area>block){
				remain+=pi*(((r+(2*count+1))*(r+(2*count+1)))-((r+2*count)*(r+2*count)))*blocks;
				--count;
			}
		}
		area=0;
		while(area<(remain)){
			area+=pi*(((r+(2*i+1))*(r+(2*i+1)))-((r+2*i)*(r+2*i)));
			i++;
		}
		if(area>(remain))
			--i;
		fout<<"Case #"<<iter+1<<": "<<i+count*blocks<<endl;
		cout<<"CASE #"<<iter+1<<": "<<i+count*blocks<<endl;
	}
	return 0;
}