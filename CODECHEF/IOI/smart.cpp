#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("smart.in","r",stdin);
	int N;
	cin>>N;
	long long int* arr=new long long int[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];
	sort(arr,arr+N);
	long long int max=0;
	for(int i=0;i<N;i++){
		if(((N-i)*arr[i])> max)
			max=(N-i)*arr[i];
	}
	cout<<max;
	return 0;
}