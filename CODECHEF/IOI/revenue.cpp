#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("revenue.in","r",stdin);
	int N,res=0;
	cin>>N;
	int* arr=new int[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			res+=abs(arr[i]-arr[j]);
		}
	}
	cout<<res;
	return 0;
}