#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Num_Test,iter;
	ifstream fin;
	fin.open("contest.txt");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N;
		fin>>N;
		vector<int> vec;
		for(int i=0;i<N;i++){
			int t;
			fin>>t;
			vec.push_back(t);
		}
		int count,res,last;
		count=res=last=0;
		for(int i=0;i<vec.size();i++){
			if(count==4){
				count=0;
				res++;
			}
			if(count==0){
				last=vec[i];
				count++;
				continue;
			}
			if((vec[i]-last)>10){
				last=last+10;
				count++;
				--i;
			}/*else if((vec[i]-last)==0){
				last=last+10;
				--i;
				count++;
			}*/else if((vec[i]-last)<=0){
				last+=10;
				--i;
				count++;
			}else{
				count++;
				last=vec[i];
			}
		}
		cout<<"Case #"<<iter+1<<": "<<((res+1)*4)-vec.size()<<endl;
	}
	return 0;
}