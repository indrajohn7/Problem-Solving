#include<bits/stdc++.h>

using namespace std;


bool row_check(char** arr,int r,int c,char a,int R,int C)
{
	for(int i=0;i<R;i++){
		if(i!=r && arr[i][c]!='.' && arr[i][c]!='+' && a!='+')
			return false;
	}
	
	return true;
}

bool col_check(char** arr,int r,int c,char a,int R,int C)
{
	for(int j=0;j<C;j++){
		if(j!=c && arr[r][j]!='.' && arr[r][j]!='+' && a!='+')
			return false;
	}
	
	return true;
}

bool diag_check(char** arr,int r,int c,char a,int R,int C)
{
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(i!=r && j!=c && (((i+j)==(r+c)) || ((i-j)==(r-c)))){
					if(arr[i][j]!='.' && arr[i][j]!='x' && a!='x'){
							return false;
					}	
				}
			}
		}
		return true;
}



int main()
{
	int iter,Num_test;
	ifstream fin;
	ofstream fout;
	fout.open("show.txt");
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
					for(int k=0;k<3;k++){
						if(row_check(arr,i,j,str[k],N,N) && col_check(arr,i,j,str[k],N,N)&&
							diag_check(arr,i,j,str[k],N,N)){
								count++;
								arr[i][j]=str[k];
								vec.push_back(make_pair(i,j));
								break;
							}
					}
				}else if(arr[i][j]!='o'){
					if(row_check(arr,i,j,'o',N,N) && col_check(arr,i,j,'o',N,N)&&
							diag_check(arr,i,j,'o',N,N)){
								count++;
								arr[i][j]='o';
								vec.push_back(make_pair(i,j));
								//break;
							}
				}
			}
		}
		
		int res=0;
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(arr[i][j]=='+' || arr[i][j]=='x')
					res+=1;
				else if(arr[i][j]=='o')
					res+=2;
			}
		}
		
		fout<<"Case #"<<iter+1<<": ";
		fout<<res<<" "<<count<<endl;
		for(int i=0;i<vec.size();i++){
			fout<<arr[vec[i].first][vec[i].second]<<" "<<vec[i].first+1<<" "<<vec[i].second+1<<endl;
		}
	}
	return 0;
}