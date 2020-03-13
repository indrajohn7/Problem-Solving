#include<bits/stdc++.h>

using namespace std;

int main()
{
	int arr[10]={1,1,2,3,3,4,5,6,4,3};
	list<int> v(arr,arr+sizeof(arr)/sizeof(int));
	v.remove(3);
	for(list<int>::iterator it=v.begin();it!=v.end();it++)
		cout<<*it<<"\t";
	cout<<endl;
	return 0;
}