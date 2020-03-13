#include<bits/stdc++.h>

using namespace std;
#define six pow(10,8)
#define PI 3.141592653589
#define area(r,h) ((PI*pow(r,2))+(2*PI*r*h))

typedef long double ld;
typedef pair<long double,long double> pii;

int count_radius(vector<pii> vec,int i,int* arr)
{
	int count=0;
	for(int j=0;j<vec.size();j++){
		if(i==j)
			continue;
		if(vec[i] >= vec[j] && arr[j]==0)
			count++;
	}
	return count;
}

int count_radius_base(vector<pii> vec,int i)
{
	int count=0;
	for(int j=0;j<vec.size();j++){
		if(i==j)
			continue;
		if(vec[i] >= vec[j])
			count++;
	}
	return count;
}


int main()
{
	int Num_test;
	ifstream fin;
	fin.open("pie.in");
	fin>>Num_test;
	freopen("pie.txt","w",stdout);
	for(int iter=0;iter<Num_test;iter++){
		int N,K;
		fin>>N>>K;
		
		vector<pii> vec;
		for(int i=0;i<N;i++){
			int r,h;
			fin>>r>>h;
			vec.push_back(make_pair(r,h));
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N-1;j++){
				if((vec[j].first*vec[j].second)>=(vec[j+1].first*vec[j+1].second)){
					if((vec[j].first*vec[j].second) == (vec[j+1].first*vec[j+1].second) && vec[j].first > vec[j+1].first){
						pair<ld,ld> p;
						p=make_pair(vec[j].first,vec[j].second);
						vec[j]=vec[j+1];
						vec[j+1]=p;
					}else{
					pair<ld,ld> p;
					p=make_pair(vec[j].first,vec[j].second);
					vec[j]=vec[j+1];
					vec[j+1]=p;
					}
				}
			}
		}
		ld max=0;
		int id=0;
		for(int i=0;i<vec.size();i++){
			ld count=(pow(vec[i].first,2))+2*vec[i].first*vec[i].second;
			if(count> max && count_radius_base(vec,i) >=(K-1)){
				id=i;
				max=count;
			}
		}
		
		vector<int> v;
		v.push_back(id);
		int count=0;
		int* arr=new int[vec.size()];
		for(int i=0;i<vec.size();i++)
			arr[i]=0;
		arr[id]=1;
		count=1;
		while(count!=K){
			int flag=0;
			for(int i=vec.size()-1;i>=0;i--){
				if(vec[v[v.size()-1]].first >= vec[i].first && arr[i]==0 && count_radius(vec,i,arr) >=(K-1-count)){
					count++;
					arr[i]=1;
					v.push_back(i);
					flag=1;
					break;
				}
			}/*
			if(flag==0){
				int p=v.back();
				arr[p]=0;
				arr[p-1]=1;
				v.pop_back();
				v.push_back(p-1);
				
			}*/
		}
		
		ld res=PI*(pow(vec[v[0]].first,2)) *six;
		for(int i=0;i<v.size();i++){
			int idx=v[i];
			res+=2*PI*vec[idx].first*vec[idx].second*six;
		}
		
		printf("Case #%d: %.8Lf\n",iter+1,res/six);
		
	}
	
	return 0;
}