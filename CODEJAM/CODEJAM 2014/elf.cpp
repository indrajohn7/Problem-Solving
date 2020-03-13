#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("elf.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		char* buff = new char[50];
		memset(buff,'\0',sizeof(buff));
		fin>>buff;
		long long int num=0,deno=0,count=0;
		while(*buff!='/'){
			num=(num*10)+(*buff-'0');
			++buff;
			}
		++buff;
		while(*buff!='\0'){
			deno=(deno*10)+(*buff-'0');
			++buff;
		}
		if(deno%2!=0)
			cout<<"CASE #"<<iter+1<<":\t"<<"IMPOSSIBLE"<<endl;
		else{
			while(num%2==0 && deno%2==0){
				num/=2;
				deno/=2;
			}
			if(deno%2==0){
			float elf=(float)num/deno;
			while(count<=40 && elf<1){
				count++;
				elf*=2;
			}
			cout<<"CASE #"<<iter+1<<":\t"<<count<<endl;
			}
			else
				cout<<"CASE #"<<iter+1<<":\t"<<"IMPOSSIBLE"<<endl;
		}
	}
	return 0;
}