#include<bits/stdc++.h>

using namespace std;



int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("file.in");
	fin>>Num_Test;
	ofstream fout;
	fout.open("file.out");
	for(iter=0;iter<Num_Test;iter++){
		int N,i,j,k;
		fin>>N;
		int** Str=new int*[2*N-1];
		for(i=0;i<2*N-1;i++)
			Str[i]=new int[N];
		for(i=0;i<2*N-1;i++){
			for(j=0;j<N;j++){
				fin>>Str[i][j];
				//=k;
			}
		}
		int a[2501]={0};
		int max=0;
		list<int> res;
		for(i=0;i<2*N-1;i++){
			for(j=0;j<N;j++){
				if(max<Str[i][j])
					max=Str[i][j];
				a[Str[i][j]]++;
			}
		}
		for(i=1;i<=max;i++){
			if(a[i]%2!=0)
				res.push_back(i);
		}
		res.sort();
		fout<<"Case #"<<iter+1<<":";
		for(list<int> ::iterator it=res.begin();it!=res.end();it++)
			fout<<" "<<*it;
		fout<<endl;
		res.resize(0);
	}
	return 0;
}