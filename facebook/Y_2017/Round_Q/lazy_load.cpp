#include<bits/stdc++.h>

using namespace std;

bool set_dummy(int dummy[],int N,int arr[],int mul,int iter){
	int count=0;
	for(int i=0;i<iter;i++){
		if(count<mul){
			if(dummy[i]==0){
				dummy[i]=1;
				count++;
			}
		}else
			break;
	}
	if(count==mul)
		return true;
	else
		return false;
}


int main()
{
	int Num_Test,iter;
	ifstream fin;
	fin.open("lazy_loading.txt");
	fin>>Num_Test;
	ofstream fout;
	fout.open("out.txt");
	for(iter=0;iter<Num_Test;iter++){
		int N;
		fin >> N;
		int* arr=new int[N];
		int* dummy=new int[N];
		for(int i=0;i<N;i++){
			arr[i]=0;
			dummy[i]=0;
		}
		for(int i=0;i<N;i++)
			fin>>arr[i];
		sort(arr,arr+N);
		int count=0;
		for(int i=N-1;i>=0;i--){
			if(dummy[i]==0){
				if(arr[i]>=50){
					count++;
					dummy[i]=1;
				}else{
					int mul=0;
					while((arr[i]*mul)<50)
						mul++;
					if(set_dummy(dummy,N,arr,mul-1,i))
						count++;
				}
			}
		}
		fout<<"Case #"<<iter+1<<": "<<count<<endl;
	}
	return 0;
}