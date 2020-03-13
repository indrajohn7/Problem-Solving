#include<bits/stdc++.h>
#define  N 2

using namespace std;

int main()
{
	int Num_Test,iter;
	ifstream fin;
	fin.open("cookies.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		float C,F,X,i=0,num_cookie,time=0;
		fin>>C;
		fin>>F;
		fin>>X;
		while(1){
			num_cookie=i*F+N;
			if((X/num_cookie)>((C/num_cookie)+(X/(num_cookie+F)))){
				time+=(C/num_cookie);
				i++;
			}
			else{
				time+=X/num_cookie;
				break;
			}
		}
		cout<<"CASE #"<<iter+1<<":\t"<<time<<endl;
	}
	return 0;
}