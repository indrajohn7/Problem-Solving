#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("prob.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,K;
		fin>>N>>K;
		float* arr=new float[N];
		for(int i=0;i<N;i++)
			fin>>arr[i];
		sort(arr,arr+N);
		float** ans=new float*[N+1];
		for(int i=0;i<=N;i++){
			ans[i]=new float[N+1];
			memset(ans[i],0.0,N+1);
		}
		ans[0][0]=1.0;
		for(int j=0;j<N;j++){
			for(int i=0;i<=j;i++){
				ans[i][j+1]+=(ans[i][j]*(1-arr[j]));
				ans[i+1][j+1]+=(ans[i][j]*(arr[j]));
			}
		}
		float max=0.0;
		for(int i=K/2+1;i<=N;i++){
			for(int j=0;j<=N;j++){
				if(max<ans[i][j])
					max=ans[i][j];
			}
		}
		cout<<"CASE	#"<<iter+1<<": "<<max<<endl;
	}
	return 0;
}