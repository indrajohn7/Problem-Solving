#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

typedef struct _files{
	int size;
	bool packed;
}files;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("packing.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int i,j,k,N,MB,count=0;
		fin>>N>>MB;
		vector<int> arr(N);
		vector<files> fe(N);
		for(i=0;i<N;i++)
			fin>>arr[i];
		
		for(i=0;i<N;i++){
			for(j=0;j<N-1;j++){
				if(arr[j]>arr[j+1]){
					int temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
		for(i=0;i<N;i++){
			fe[i].size=arr[i];
			fe[i].packed=false;
		}
		int file_count=0;
		for(i=N-1;i>=0 && file_count<N;i--){
			int max=0,flag=0;
			for(j=0;j<N;j++){
				if(fe[i].packed==false && fe[j].packed==false){
					if(fe[i].size+fe[j].size<=MB){
					flag=1;
					if(max<fe[i].size+fe[j].size){
						max=fe[i].size+fe[j].size;
					    k=j;
					}
				}
				else
					break;
			 }
			}
			if(flag==0){
				file_count++;
				fe[i].packed=true;
			    count++;
			}
			else{
				fe[k].packed=true;
				fe[i].packed=true;
				file_count+=2;
				count++;
			}				
		}
		cout<<"CASE #"<<iter+1<<":\t"<<count<<endl;
	}
	return 0;
}