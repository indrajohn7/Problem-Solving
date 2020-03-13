#include<bits/stdc++.h>

using namespace std;



bool check_on(char** arr,int r,int c,char a,int R,int C)
{
	for(int i=0;i<R;i++){
		if(i!=r && arr[i][c]!='.' && arr[i][c]!='+')
			return false;
	}
	for(int j=0;j<C;j++){
		if(j!=c && arr[r][j]!='.' && arr[r][j]!='+')
			return false;
	}
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(i!=r && j!=c && (((i+j)==(r+c)) || ((i-j)==(r-c)))){
				if(arr[i][j]!='x' || arr[r][c]!='x')
					return false;
			}
		}
	}
	
	arr[r][c]=true;
	return true;
	
}


int main()
{
	int iter,Num_test;
	ifstream fin;
	fin.open("show.in");
	fin>>Num_test;
	for(iter=0;iter<Num_test;iter++){
		int N,M;
		fin>>N>>M;
		char** arr=new char*[N];
		for(int i=0;i<N;i++){
			arr[i]=new char[N];
			memset(arr[i],'.',N);
		}
		//memset(arr,'.',N*N);
		
		for(int i=0;i<M;i++){
			int r,c;
			char a;
			fin>>a>>r>>c;
			arr[r-1][c-1]=a;
		}
		
		char str[3]={'o','+','x'};
		int count=0;
		typedef pair<int,int> pii;
		vector<pii> vec;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(arr[i][j]=='.'){
					if(check_on(arr,i,j,'o',N,N)){
						count++;
						vec.push_back(make_pair(i,j));
					}else if(check_on(arr,i,j,'+',N,N)){
						count++;
						vec.push_back(make_pair(i,j));
					}else if(check_on(arr,i,j,'x',N,N)){
						count++;
						vec.push_back(make_pair(i,j));
					}
				}else if(check_on(arr,i,j,'o',N,N)){
					count++;
					vec.push_back(make_pair(i,j));
				}
			}
		}
		
		int res=0;
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(arr[i][j]=='+' || arr[i][j]=='x')
					res+=1;
				else if(arr[i][j]=='o')
					res+=1;
			}
		}
		
		cout<<"Case #"<<iter+1<<": ";
		cout<<res<<" "<<count<<endl;
		for(int i=0;i<vec.size();i++){
			cout<<arr[vec[i].first][vec[i].second]<<" "<<vec[i].first<<" "<<vec[i].second<<endl;
		}
	}
	return 0;
}