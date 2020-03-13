#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Num_Test,iter;
	ifstream fin;
	freopen("out_slides.txt","w");
	fin.open("slides.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		long long int B,M,slides=0;
		fin>>B>>M;
		int reach=B,dummy=1;
		cout<<"CASE #"<<iter+1<<": ";
		if(M> (1LL<<(B-2)))
			cout<<"IMPOSSIBLE\n";
		else{
			cout<<"POSSIBLE\n";
			int** arr=new int*[B];
			for(int i=0;i<B;i++){
				arr[i]=new int[B];
			}
			for(int i=0;i<B;i++){
				for(int j=0;j<B;j++)
					arr[i][j]=0;
			}
			int source,dest,start;
			source=start=dummy;
			dest=reach;
			while(slides<M){
				dest=reach;
				if(source>0 && dest<=reach && arr[source-1][dest-1]==0){
					while(source>0 && dest<=reach && arr[source-1][dest-1]==0){
						arr[source-1][dest-1]=1;
						dest=source;
						if(arr[dummy-1][source-1]==0)
							source=dummy;
						else if(source>1)
							source-=1;
					}
					slides++;
					start++;  //handle source pointer properly
					source=start;
				}
				if(source==reach)
					source=start=dummy;
			}
			for(int i=0;i<B;i++){
				for(int j=0;j<B;j++){
					if(i==j)
						arr[i][j]=0;
					cout<<arr[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}