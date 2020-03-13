#include<bits/stdc++.h>

using namespace std;

long long md=pow(10,9)+7;

long long int fact(int n)
{
	if(n==0 || n==1)
		return 1;
	else 
		return n*fact(n-1);
}


long long int combination(int n,int r)
{
	return (fact(n)/(fact(n-r)*fact(r)));
}




int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("camp.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,X,i,j,k;
		long long int res=0;
		fin>>N>>X;
		if(N==2 && X==0){
			res=4;
		}
		else if(N==2 && X>=1){
			res=2;
		}
		else if(N>=3 && X<=N-3){
			long long int ans3=combination(N,N-3)*fact(3);
			for(i=N;i>=4;i--)
				ans3*=i;
			long long int ans2=combination(N,N-2)*fact(2);
			for(i=N;i>=3;i--)
				ans2*=i;
			long long int ans0=fact(N);
			res=ans3+ans2+ans0;
		}
		else if(N>=3 && X==N-2){
			long long int ans2=combination(N,N-2)*2;
			for(i=N;i>=3;i--)
				ans2*=i;
			long long int ans0=fact(N);
			res=ans2+ans0;
		}
		else if(N>=3 && X>N-2){
			res=fact(N);
		}
		cout<<"CASE #"<<iter+1<<":\t"<<(res%md)<<endl;
	}
	return 0;
}