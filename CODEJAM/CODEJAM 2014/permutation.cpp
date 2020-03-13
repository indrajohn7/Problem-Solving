#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Num_Test,iter;
	ifstream fin;
	//fin.open("permute.in");
	fin.open("permute_large.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,i,p,count;
		fin>>N;
		int arr[N],str[N];
		for(i=0;i<N;i++)
			fin>>arr[i];
		for(i=0;i<N;i++)
			str[i]=i;
		srand(time(NULL));
		for(i=0;i<N;i++){
			count=0;
			while(1){
				p=rand()%N;
				if(p>=i && p<=N-1)
					break;
			}
			swap(str[i],str[p]);
			for(int j=0;j<N;j++){
				if(str[j]==arr[j])
					count++;
			}
			if(count==N)
				break;
		}
		cout<<"CASE #"<<iter+1<<":\t";
		if(count==N)
			cout<<"GOOD \n";
		else
			cout<<"BAD \n";
			
	}
	return 0;
}