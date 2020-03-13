#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,bool> pib;

int main()
{
	freopen("covering.in","r",stdin);
	int N;
	cin>>N;
	vector<pib> vpb;
	for(int i=0;i<N;i++){
		int a,b;
		cin>>a>>b;
		vpb.push_back(make_pair(make_pair(a,b),false));
	}
	//Sorted with the first element
	for(int i=0;i<N;i++){
		for(int j=0;j<N-1;j++){
			if(vpb[j].first.first>vpb[j+1].first.first){
				pib p;
				p=vpb[j];
				vpb[j]=vpb[j+1];
				vpb[j+1]=p;
			}
		}
	}
	vector<pii> vp;
	vp.push_back(make_pair(vpb[0].first.first,vpb[0].first.second));
	for(int i=1;i<N;i++){
		int j=0;
		for(j=0;j<vp.size();j++){
			if(vpb[i].first.first>=vp[j].first && vpb[i].first.first<=vp[j].second){
				int m=min(vp[j].second,vpb[i].first.second);
				vp[j].first=vpb[i].first.first;
				vp[j].second=m;
				break;
			}
		}
		if(j==vp.size())
			vp.push_back(make_pair(vpb[i].first.first,vpb[i].first.second));
	}
	cout<<vp.size();
	return 0;
}