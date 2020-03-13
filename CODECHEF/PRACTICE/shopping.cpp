#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef struct goods{
	int cost;
	int number;
	bool stat;
	int weight;
	goods(int c,int n,bool s,int w){
		cost=c;
		number=n;
		stat=s;
		weight=w;
	}
};

typedef struct _node{
	vector<int> paths;
	vector<goods> v;
	int penalty;
}node;

int main()
{
	int Num_Test,iter;
	ifstream fin;
	fin.open("shopping.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,M,K,F;
		vector<pii> vec;
		vector<node> Nds(k+1);
		pii p;//=make_pair(0,0);
	//	vec.push_back(p);
		for(int i=0;i<K;i++){
			int a,b,weight;
			fin>>a>>b;
			weight=b;
			p=make_pair(a,b);
			vec.push_back(p);
			for(int j=0;j<a;j++){
				fin>>a>>b;
				p=make_pair(a,b);
				goods g(b,i+1,false,weight);
				Nds[a].v.push_back(g);
			}
		}
		for(int i=0;i<M;i++){
			int x,y,z;
			fin>>x>>y>>z;
			Nds[x].paths.push_back(y);
			Nds[y].paths.push_back(x);
		}
		cost=0;
		int reached=N,bought=0;
		vector<int> goody;
		vector<int> result;
		while(cost<F && reached!=1 && bought!=k){
			int max=0,ind;
			
			for(int i=0;i<Nds[reached].v.size();i++){
				for(int j=0;j<Nds[reached].v.size()-1;j++){
					if(Nds[reached].v[j].weight>Nds[reached].v[j+1].weight){
						int t;
						t=Nds[reached].v[j].weight;
						Nds[reached].v[j].weight=Nds[reached].v[j+1].weight;
						Nds[reached].v[j+1].weight=t;
					}
				}
			}
			
			//sort(Nds[reached].v.begin(),Nds[reached].v.end());
			for(int i=Nds[reached].v.size()-1;i>=0;i--){
				if(cost+Nds[reached].v[i].cost<F && bought!=k){
						goody.push_back(Nds[reached].v[i].number);
						bought++;
				}	
			}
			/*
			for(int i=0;i<Nds[reached].paths.size();i++){
				for(int j=0;j<Nds[reached].paths.size()-1;j++){
					if(Nds[reached].paths[j]>Nds[reached].paths[j+1]){
						int t;
						t=Nds[reached].paths[j];
						Nds[reached].paths[j]=Nds[reached].paths[j+1];
						Nds[reached].paths[j+1]=t;
					}
				}
			}
			*/
			sort(Nds[reached].paths.begin(),Nds[reached].paths.end());
			
		}
	}
}