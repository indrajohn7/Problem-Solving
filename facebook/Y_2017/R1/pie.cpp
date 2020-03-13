#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("progress_pie.txt");
	fin>>Num_Test;
	ofstream fout;
	fout.open("pie.txt");
	for(iter=0;iter<Num_Test;iter++){
		int N,M;
		fin>>N>>M;
		int** arr=new int*[N];
		for(int i=0;i<N;i++)
			arr[i]=new int[M];
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				int t;
				fin>>t;
				arr[i][j]=t;
			}
			sort(arr[i],arr[i]+M);
		}
		int* used=new int[N];
		memset(used,0,sizeof(int)*N);
		long long int count=0,expense=0;
		while(count!=N){
			if(count==0){
				count++;
				used[0]=1;
			}else{
				expense=0;
				int idx=0;
				for(int i=1;i<=count;i++){
					if(used[i]<M){
						if((arr[idx][used[idx]]+(pow(used[idx]+1,2)-pow(used[idx],2))) > (arr[i][used[i]]+(pow(used[i]+1,2)-pow(used[i],2)))){
							idx=i;
						}else if(used[idx]>=M){
							idx=i;
						}
					}
				}
				count++;
				used[idx]+=1;
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<used[i];j++){
				expense+=arr[i][j];
			}
			expense+=pow(used[i],2);
		}
		fout<<"Case #"<<iter+1<<": "<<expense<<endl;
	}
	return 0;
}