#include<bits/stdc++.h>

using namespace std;

long long int interval_check(vector<long long int> vec)
{
	long long int len=0,idx=0;;
	for(int i=0;i<vec.size()-1;i++){
		if((vec[i+1]-vec[i]) > len){
			len=(vec[i+1]-vec[i]);
			idx=vec[i];
		}
	}
	return idx;
}

int main()
{
	int iter,Num_test;
	ifstream fin;
	ofstream fout;
	fout.open("stall.txt");
	fin.open("stall.in");
	fin>>Num_test;
	for(iter=0;iter<Num_test;iter++){
		long long int N,K,len,ls,rs;
		ls=rs=0;
		fin>>N>>K;
		len=N+2;
		long long int* arr=new long long int[N+2];
		for(long long int i=0;i<N+2;i++){
			arr[i]=0;
		}
		
		//memset(arr,0,sizeof(int)*(N+2));
		arr[0]=1;
		arr[N+1]=1;
		bool zero=false;
		
		if(N%2==0 && K>(N/2))
			zero=true;
		else if((N%2) && K>((N+1)/2))
			zero=true;
		else{
		//	int n=0,last=0,current=N+1;
		//	while(K>(pow(2,n)-1))
		//		n++;
			long long int count=0,i=1;
			vector<long long int> vec;
			vec.push_back(0);
			vec.push_back(len-1);
			/*
			for(int i=1;i<=n;i++){
				vector<int> v;
				for(int k=0;k<vec.size()-1;k++){*/
				while((vec.size()-2)<K){
					long long int idx=interval_check(vec);
					vec.push_back(idx+(len/(pow(2,i))));
					arr[(idx+(len/((long long int)pow(2,i))))]=1;
					if((vec.size()-2)==(K)){
						int pos=idx+(len/(pow(2,i)));
						for(int p=pos-1;p>=0;p--){
							if(arr[p]==0)
								ls++;
							else
								break;
						}
						for(int p=pos+1;p<len;p++){
							if(arr[p]==0)
								rs++;
							else
								break;
						}
						break;
					}
					sort(vec.begin(),vec.end());
					if(((vec.size()-2))==((pow(2,i))-1))
						i++;
				}
				/*
				}
				for(int k=0;k<v.size();k++){
					vec.push_back(v[k]);
				}
				sort(vec.begin(),vec.end());
				v.clear();
			}*/
		}
		
		fout<<"Case #"<<iter+1<<": ";
		if(!zero){
			long long int maxi=max(ls,rs);
			long long int mini=min(ls,rs);
			fout<<maxi<<" "<<mini<<endl;
		}else{
			fout<<ls<<" "<<rs<<endl;
		}	
	}
	return 0;
}