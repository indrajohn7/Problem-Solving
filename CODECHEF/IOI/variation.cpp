#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("variation.in","r",stdin);
	int N,K,count=0;
	cin>>N>>K;
	int* arr=new int[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];
	sort(arr,arr+N);
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			if(abs(arr[i]-arr[j])>=K){
				count+=(N-j);
				break;
			}
		}
	}
	cout<<count;
	return 0;
}