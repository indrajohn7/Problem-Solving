#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int main()
{
	freopen("wormholes1.in","r",stdin);
	int N,X,Y;
	cin>>N>>X>>Y;
	vector<pii> vp;
	for(int i=0;i<N;i++){
		int S,E;
		cin>>S>>E;
		vp.push_back(make_pair(S,E));
	}
	int* S=new int[X];
	int* E=new int[Y];
	for(int i=0;i<X;i++)
		cin>>S[i];
	for(int i=0;i<Y;i++)
		cin>>E[i];
	sort(S,S+X);
	sort(E,E+Y);
	for(int i=0;i<N;i++){
		for(int j=0;j<N-1;j++){
			if((vp[j].second-vp[j].first)>(vp[j+1].second-vp[j+1].first)){
				pii p;
				p=vp[j];
				vp[j]=vp[j+1];
				vp[j+1]=p;
			}
		}
	}
	int min=9999999;
	for(int i=0;i<N;i++){
		if(i!=0){
			if(min<(vp[i].second-vp[i].first+1))
				break;
		}
		int t1,t2;
		for(int j=0;j<X;j++){
			if(S[j]<=vp[i].first)
				t1=S[j];
			else
				break;
		}
		for(int j=0;j<Y;j++){
			if(E[j]>=vp[i].second && t1<E[j]){
				t2=E[j];
				break;
			}
			if(i!=0 && (min<(E[j]-t1+1))){
				t2=E[j];
				break;
			}
		}
		if((t2-t1+1)>0 && (t2-t1+1)<min)
			min=(t2-t1+1);
	}
	cout<<min;
	return 0;
}
