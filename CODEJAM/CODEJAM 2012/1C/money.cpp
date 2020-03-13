#include<bits/stdc++.h>

using namespace std;
typedef pair<long long int,int> pii;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("money.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int C,D,V;
		fin>>C>>D>>V;
		vector<long long int> v;
		for(int i=0;i<D;i++){
			int a;
			fin>>a;
			for(int i=0;i<C;i++)
				v.push_back(a);
		}
		int ans=0,curr=0;
		for(int i=1;i<=V;i++){
			curr=0;
			int temp=-1,j=0,dummy=v.size();
			while(curr<i && dummy>0){
				temp=-1;
			for(j=0;j<dummy;j++){
				if(v[j]==i){
					curr=i;
					break;
				}
				else if(curr+v[j]>i){
					temp=j;
					break;
				}
				else if(curr+v[j]==i){
					curr=i;
					break;
				}
				else if(curr!=0 && v[j]>=curr){
					temp=j;
					break;
				}
				else if(v[j]>i){
					temp=j;
					break;
				}
			}
			if((temp!=-1 || j==dummy )&& curr<i){
				if(temp!=-1){
					curr+=v[temp-1];
					dummy=temp-1;
				}
				else{
					curr+=v[j-1];
					dummy=j-1;
				}
			}
			}
			if(curr!=i){
				for(j=0;j<C;j++)
					v.push_back(i);
				ans++;
			}
			sort(v.begin(),v.end());
		}
		cout<<"Case #"<<iter+1<<": "<<ans<<endl;
	}
	return 0;
}