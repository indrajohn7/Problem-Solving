#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("safety.in");
	fin>>Num_Test;
	ofstream fout;
	fout.open("out.txt");
	for(iter=0;iter<Num_Test;iter++){
		int N;
		fin>>N;
		vector<int> arr(N);
		vector<int> arr1(N);
		float sum=0;
		for(int i=0;i<N;i++){
			fin>>arr[i];
			sum+=arr[i];
			arr1[i]=arr[i];
		}
		sort(arr1.begin(),arr1.end());
		int max,max_2;
		max=arr1[N-1];
		for(int i=N-1;i>=0;i--){
			if(arr1[i]<max){
				max_2=arr[i];
				break;
			}
		}
		float obt,percent,a[N];
		obt=(max+max_2)/2;
		for(int i=0;i<N;i++){
			if(obt-arr[i]>0)
				a[i]=(float)((obt-arr[i])/sum);
			else
				a[i]=0;
		}
		cout<<"Case #"<<iter+1<<":";
		for(int i=0;i<N;i++)
			printf(" %.6f",a[i]*100);
		cout<<endl;
	}
	return 0;
}