#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("bracket.in","r",stdin);
	int N,depth=0,depth_pos,max_len=0,max_pos=0,open=0,length=0;
	cin>>N;
	int* arr=new int[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];
	for(int i=0;i<N;i++){
		if(arr[i]==1){
			open++;
			if(open>1)
				length++;
		}
		else if(arr[i]==2){
			open--;
			if(open>0)
				length++;
		}
		if(length>max_len){
			max_len=length;
			max_pos=i-max_len;
		}
		if(open==0)
			length=0;
		if(open>depth){
			depth=open;
			depth_pos=i+1;
		}
	}
	cout<<depth<<" "<<depth_pos<<" "<<max_len+2<<" "<<max_pos+1;
	return 0;
}