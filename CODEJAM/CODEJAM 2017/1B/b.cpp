#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter, Num_test;
	ifstream fin;
	fin.open("b.in");
	fin>>Num_test;
	for(iter=0;iter<Num_test;iter++){
		int N,R,O,Y,G,B,V;
		fin>>N>>R>>O>>Y>>G>>B>>V;
		vector<char> v;
		bool impos=false;
		if(O==0 && G==0 && V==0){
			int arr[3];
			char barr[3]={'R','B','Y'};
			arr[0]=R;
			arr[1]=B;
			arr[2]=Y;
			if(R!=0){
				v.push_back('R');
				arr[0]--;
			}
			else if(Y!=0){
				v.push_back('Y');
				arr[2]--;
			}
			else{
				v.push_back('B');
				arr[1]--;
			}
			while(v.size()!=N){
				if (v.size()!=N-1){
					int len=v.size()-1;
					if(v[len]=='R' && arr[1]!=0){
						v.push_back('B');
						arr[1]--;
					}else if(v[len]=='R' && arr[2]!=0){
						v.push_back('Y');
						arr[2]--;
					}else if(v[len]=='R'){
						impos=true;
						break;
					}else if(v[len]=='B' && arr[0]!=0){
						v.push_back('R');
						arr[0]--;
					}else if(v[len]=='B' && arr[2]!=0){
						v.push_back('Y');
						arr[2]--;
					}else if(v[len]=='B'){
						impos=true;
						break;
					}else if(v[len]=='Y' && arr[0]!=0){
						v.push_back('R');
						arr[0]--;
					}else if(v[len]=='Y' && arr[1]!=0){
						v.push_back('B');
						arr[1]--;
					}else if(v[len]=='Y'){
						impos=true;
						break;
					}
				}else{
					
					int len=v.size()-1;
					int t=rand()%3;
					int flag=0;
					for(int i=0;i<3;i++){
						if(barr[i]!=v[len] && barr[i]!=v[0] && arr[i]!=0){
							v.push_back(barr[i]);
							flag=1;
							break;
						}
					}
					if(flag==0)
						impos=true;
					
				}
				
			}
		}else{
			int i=1;
		}
		cout<<"Case #"<<iter+1<<": ";
		if(impos==true){
			cout<<"IMPOSSIBLE\n";
		}else{
			for(int i=0;i<v.size();i++)
				cout<<v[i];
			cout<<endl;
		}
	}
	return 0;
}