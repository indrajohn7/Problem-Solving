#include<bits/stdc++.h>

using namespace std;
#define MAX pow(10,5)

int main()
{
	freopen("bamboo.in","r",stdin);
	int N;
	cin>>N;
	int* arr=new int[N];
	int stat[100001];
	memset(stat,0,MAX+1);
	for(int i=0;i<N;i++){
		int t;
		cin>>t;
		arr[i]=t;
		stat[t]=1;
	}
	sort(arr,arr+N);
	int max=0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			int diff=arr[j]-arr[i];
			int count=0;
			if(max && (arr[i]+diff*(max-1))<=MAX && stat[arr[i]+diff*(max-1)]==0)
				continue;
			while((arr[i]+diff*(max-1))<=MAX && stat[arr[i]+diff*count]){
				count++;
			}
			if(count>max)
				max=count;
		}
	}
	cout<<max;
	return 0;
}