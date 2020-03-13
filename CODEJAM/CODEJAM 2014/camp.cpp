#include<bits/stdc++.h>

using namespace std;

long long md=pow(10,9)+7;

long long int fact(int n)
{
	if(n==0 || n==1)
		return 1;
	else 
		return (n*fact(n-1))%md;
}


long long int combination(int n,int r)
{
	return (fact(n)/(fact(n-r)*fact(r)))%md;
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
            long long int ans=0;			
			for(i=X;i<=N;i++){
				int plus=0;
				ans+=(combination(N,i)*fact(i))%md;
				if(i==N-1)
					continue;
				if(i==N)
					break;
				if((N-i)%3==0){
					int block=(N-i)/3;
					plus+=pow(fact(3),block);
				}
				if((N-i)%2==0){
					int block=(N-i)/2;
					plus+=pow(fact(2),block);
				}
				if((N-i)%3==2 && (N-i)%2==1){
					int block=(N-i)/3;
					plus+=(block+1)*2*pow(fact(3),block);
				}
				if((N-i)%3==1 && (N-i)%2==1){
					int block=(N-i)/3;
					plus+=combination(block+1,block-1)*pow(fact(3),block-1)*4;
				}
				ans*=plus%md;
			}
			res=ans;
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