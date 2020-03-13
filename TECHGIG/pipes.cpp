#include<bits/stdc++.h>

using namespace std;

int* getjoinedpipes(int input1[],int input2)
{
	vector<int> vec(input1,input1+input2);
	sort(vec.begin(),vec.end());
	int* res=new int[input2-1];
/*	if(input2==1){
		int* res1=new int[1];
		res1[0]=0;
	} */
	for(int i=0;i<input2-1;i++)
		res[i]=0;
	int k=0;
	if(input2>1){
	for(int i=0;i<vec.size();i++){
		if(i==0){
			res[k]=vec[i]+vec[i+1];
			i++;
			k++;
		}
		else{
			res[k]=res[k-1]+vec[i];
			k++;
		}
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<k-1;j++){
			if(res[j]>res[j+1])
				swap(res[j],res[j+1]);
		}
	}
	}
	if(input2==1){
		int* res1=new int[1];
		res1[0]=0;
		return res1;
	}
	if(input2>1)
		return res;
}

/*

int main()
{
	int N;
	cout<<"NUM OF ELEMENTS::\n";
	cin>>N;
	int* arr=new int[N];
	cout<<"ELEMENTS:\n";
	for(int i=0;i<N;i++)
		cin>>arr[i];
	int* res=new int[N];
	res=getjoinedpipes(arr,N);
	for(int i=0;i<N-1;i++)
		cout<<res[i]<<"\t";
	if(N==1)
		cout<<res[0]<<"\t";
	cout<<endl;
	cout<<endl;
	return 0;
}

*/