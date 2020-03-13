#include<bits/stdc++.h>
/* Check feasibility + last 2 sum */

using namespace std;

#define cal_min_day(A,N) (A[N]<A[N+1])?((A[N]<A[N+2])?N:(N+2)):((A[N+1]<A[N+2])?(N+1):(N+2))

int main()
{
	freopen("supw.in","r",stdin);
	int N,time=0,work=0,first,second,third,days=0;
	cin>>N;
	int* arr=new int[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];
	first=arr[0];
	second=arr[1];
	third=arr[2];
	/*FIRST CASE*/
	int i=1;
	while(i<=(N-3)){ //&& i>=(N-3)){
		i=cal_min_day(arr,i);
		first+=arr[i];
		i++;
	}
	i=2;
	while(i<=(N-3)){ //&& i>=(N-3)){
		i=cal_min_day(arr,i);
		second+=arr[i];
		i++;
	}
	i=3;
	while(i<=(N-3)){ //&& i>=(N-3)){
		i=cal_min_day(arr,i);
		third+=arr[i];
		i++;
	}
	work=(first<second)?((first<third)?first:third):((second<third)?second:third);
	cout<<work;
	return 0;
}
