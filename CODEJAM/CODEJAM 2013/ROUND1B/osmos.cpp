#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("osmos.in");
	ofstream fout;
	fout.open("osmos.out");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		long long int A,N,i,j,k,count=0;
		fin>>A>>N;
		vector<long long int> v;
		for(i=0;i<N;i++){
			fin>>k;
			v.push_back(k);
		}
		sort(v.begin(),v.begin()+N);
		while(v.size()>0){
			if(A==1){
				count=v.size();
				break;
			}
			else{
				if(A>v.front()){
					A+=v.front();
				//	vector<long long int> ::iterator it=v.begin();
					v.erase(v.begin());
				}
				else if(2*A-1<=v.front()){
				//	vector<long long int> ::iterator it=v.begin();
					v.erase(v.begin());
					count++;
				}
				else if(A<=v.front()){
					v.push_back(A-1);
					sort(v.begin(),v.begin()+v.size());
					count++;
				}
			}
		}
		fout<<"Case #"<<iter+1<<": "<<count<<endl;
	}
	return 0;
} 