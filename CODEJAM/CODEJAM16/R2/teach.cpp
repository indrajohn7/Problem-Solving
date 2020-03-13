#include<bits/stdc++.h>

using namespace std;
#define MAX 200000
typedef pair<char,int> pci;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("teach.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		char* stream=new char[MAX];
		fin>>stream;
		vector<pci> req;
		long long int marks=0;
		pair<char,int> p=make_pair(stream[0],10);
		req.push_back(p);
		for(int i=1;i<strlen(stream);i++){
			if(req.size()==0){
				p=make_pair(stream[i],10);
				req.push_back(p);
			}
			else if(req.size()>0 && stream[i]==req[req.size()-1].first){
				marks+=req.back().second;
				req.pop_back();
			}
			else{
				if((strlen(stream)-i)>req.size()+1){
					p=make_pair(stream[i],10);
					req.push_back(p);
				}
				else{
					marks+=req.back().second-5;
					req.pop_back();
				}
			}
		}
		cout<<"CASE #"<<iter+1<<": "<<marks<<endl;
	}
	return 0;
}