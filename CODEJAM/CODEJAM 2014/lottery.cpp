#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("lottery.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,A,B,K,i,temp_A,temp_B=0,count=0;
		fin>>A>>B>>K;
		//OPERATION   :: A&B
		if(B>K){
			count=B*K;
			temp_A=K;
			int temp,pow_A,pow_B,pow_K;
		//	pow_A= power(A-1);
		//	pow_B=power(B-1);
		//	pow_K=power(K-1);
		//	if((pow_B>pow_A) && (pow_A==pow_K)){
			while(temp_A<A){
				temp_B=0;
				while(temp_B<B){
					temp=temp_A&temp_B;
					if(temp<K)
						count++;
					temp_B++;
				}
				temp_A++;
			}
			cout<<"CASE #"<<iter+1<<":\t"<<count<<endl;
	//		}
	//		else if((pow_A==pow_B) && (pow_A>pow_K)){
		//		int num_bit=Bits(K-1);
				
		//	}
		}
	}
	return 0;
}