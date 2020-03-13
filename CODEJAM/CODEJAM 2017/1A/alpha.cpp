#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_test;
	ifstream fin;
	ofstream fout;
	fout.open("alpha.txt");
	fin.open("alpha.in");
	fin>>Num_test;
	for(iter=0;iter<Num_test;iter++){
		int R,C;
		fin>>R>>C;
		char** arr=new char*[R];
		for(int i=0;i<R;i++)
			arr[i]=new char[C];
		int** pos=new int*[R];
		for(int i=0;i<R;i++){
			pos[i]=new int[C];
			memset(pos[i],0,4*C);
		}
		int alpha[26];
		memset(alpha,0,104);
		vector<char> vec;
		map<char*,int> v;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				fin>>arr[i][j];
				if(arr[i][j]!='?')
					vec.push_back(arr[i][j]);
				else
					pos[i][j]=1;
			}
		}
		
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(arr[i][j]=='?')
					arr[i][j]=vec[0];
			}
		}
		
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				//int k=0;
		label:		if(pos[i][j]==1){
				//	char c=vec[k++];
					vector<char> s;
					for(int p=i-1;p<=i+1;p++){
						for(int q=j-1;q<=j+1;q++){
							if(p>= 0 && q>=0 && p<R && q<C){
								s.push_back(arr[p][q]);
							}
								
						}
					}
					char* str=new char[1000];
					memset(str,'\0',1000);
					for(int k=0;k<s.size();k++)
						str[k]=s[k];
					map<char*,int>::iterator it=v.begin();
					it=v.find(str);
					if(it==v.end()){
						v[str]=1;
					}else{
						arr[i][j]=vec[rand()%vec.size()];
						goto label;
					}
				}
			}
		}
		
		fout<<"Case #"<<iter+1<<":"<<endl;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				fout<<arr[i][j];
			}
			fout<<endl;
		}
		
	}
	return 0;
}