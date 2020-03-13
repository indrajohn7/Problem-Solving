#include<bits/stdc++.h>

using namespace std;
#define SIZE 1001

void flip(char* buff,int len,int idx,int N)
{
	for(int i=idx;i<(idx+N);i++){
		if(buff[i]=='+')
			buff[i]='-';
		else
			buff[i]='+';
	}
}


int main()
{
	int iter,Num_test;
	ifstream fin;
	ofstream fout;
	fout.open("pan.txt");
	fin.open("pan.in");
	fin>>Num_test;
	for(iter=0 ;iter<Num_test;iter++){
		char* buff= new char[SIZE];
		memset(buff,'\0',SIZE);
		int K,len,count=0;
		bool impos=false;
		fin>>buff>>K;
		len=strlen(buff);
		for(int i=0;i<len;i++){
			if((i+K)>len)
				break;
			if(buff[i]=='-'){
				flip(buff,len,i,K);
				count++;
			}
		}
		
		for(int i=0;i<len;i++){
			if(buff[i]=='-'){
				impos=true;
				break;
			}
		}
		fout<<"Case #"<<iter+1<<": ";
		if(impos)
			fout<<"IMPOSSIBLE\n";
		else
			fout<<count<<endl;
	}
	
	return 0;
}
