#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	ofstream fout;
	fout.open("out_small.in");
	fin.open("sheep_small.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		long long int N,count=0,mul=1,temp,temp1;
		fin>>N;
		int arr[10];
		for(int i=0;i<10;i++)
			arr[i]=-1;
		temp1=N;
		while(count!=10 && N!=0){
			temp=temp1;
			count=0;
			while(temp!=0){
				arr[temp%10]++;
				temp=temp/10;
			}
			for(int i=0;i<10;i++){
				if(arr[i]!=-1)
					count++;
			}
			if(count!=10){
				mul++;
				temp1=N*mul;
			}
		}
		if(N!=0)
			fout<<"CASE #"<<iter+1<<": "<<temp1<<endl;
		else
			fout<<"CASE #"<<iter+1<<": "<<"INSOMNIA"<<endl;
	}
	return 0;
}