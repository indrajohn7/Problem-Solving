#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>

using namespace std;

int* uniqueValue(int input1,int input2[])
{
	//Write code here
	int* arr=new int[input1];
	for(int i=0;i<input1;i++)
	    arr[i]=0;
	 std::cout<<"HI\n";
	for(int i=0;i<input1;i++){
	    int k=0,l=0;
	    while(k<=input2[i]){
	        if(arr[l++]==0)
	            k++;
	      /*  else{
	            l++;
				k++;
			} */
	    }
	    arr[--l]=i+1;
	}
	for(int i=0;i<input1;i++)
	    cout<<arr[i]<<"\t";
	cout<<"\n";
	return arr;
}


int main()
{
	ifstream fin;
	fin.open("h.in");
	int Num_Test,iter;
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N;
		fin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
			fin>>arr[i];
		int* ret=uniqueValue(N,arr);
		for(int i=0;i<N;i++)
			cout<<*(ret++)<<"\t";
		cout<<"\n";
	}
	return 0;
}