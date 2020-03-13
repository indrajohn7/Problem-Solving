#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("pair.in","r",stdin);
	int N,K,pair=0;
	cin>>N>>K;
	int* arr=new int[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];
	sort(arr,arr+N);
	for(int i=0;i<N-1;i++){
		if(arr[i]>=K)
			break;
		for(int j=i+1;j<N;j++){
			if((arr[i]+arr[j])<K)
				pair++;
			else
				break;
		}
	}
	cout<<pair;
	return 0;
}