#include<bits/stdc++.h>

using namespace std;
#define MAX 1000
int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("up.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int max=0,swaping=0,i,j,N,idx;
		fin>>N;
		int arr[N];
		for(i=0;i<N;i++){
			fin>>arr[i];
			if(max<arr[i]){
				max=arr[i];
				idx=i;
			}
		}
	    int temp_up[MAX],temp_down[MAX];
		for(i=0;i<N;i++){
			if(i<idx)
				temp_up[i]=arr[i];
			else if(i>idx)
				temp_down[i-idx-1]=arr[i];
		}
		for(i=0;i<idx;i++){
			for(j=0;j<idx-1;j++){
				if(temp_up[j]>temp_up[j+1]){
					swap(temp_up[j],temp_up[j+1]);
					swaping++;
			    }
		    }
	    }
		for(i=0;i<N-idx-1;i++){
			for(j=0;j<N-idx-2;j++){
				if(temp_up[j]<temp_up[j+1]){
					swap(temp_up[j],temp_up[j+1]);
					swaping++;
			    }
		    }
	    }
		cout<<"CASE #"<<iter+1<<":\t"<<swaping<<endl;
	}
	return 0;
}