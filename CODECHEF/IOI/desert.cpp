#include<bits/stdc++.h>

using namespace std;
#define cal_min_pos(A,N) (A[N]<A[N+1])?N:N+1 

typedef struct _node{
	int pos;
	int val;
	bool check;
}node;

int main()
{
	freopen("desert.in","r",stdin);
	int N,cost=0,check=0;
	cin>>N;
	int* arr=new int[N];
	vector<node> nd;
	for(int i=0;i<N;i++){
		node _nd;
		cin>>_nd.val;
		_nd.pos=i;
		_nd.check=false;
		nd.push_back(_nd);
	}
	for(int i=0;i<N;i++){
			int pos;
		//	pos=(i!=N-1)?(nd[i].val<nd[i+1].val)?i:(nd[i].val==nd[i+1].val)?(i>0)?(i!=N-1)?:i:(nd[i].val<nd[0].val)?i:0;
			if(i!=N-1){
				if(nd[i].val<nd[i+1].val)
					pos=i;
				else if(nd[i].val>nd[i+1].val)
					pos=i+1;
				else{
					if (i==0)
						pos=i;
					else if(i>0 && i!=N-1){
						if(nd[i-1].check==false)
							pos=i;
						else
							pos=i+1;
					}
				}
			}
			else{
				if(nd[i].val<nd[0].val)
					pos=i;
				else if(nd[i].val>nd[0].val)
					pos=0;
				else{
					pos=(nd[0].check)?0:i;
				}
			}
			if(nd[pos].check==false){
				cost+=nd[pos].val;
				nd[pos].check=true;
			}
	}
	cout<<cost;
	return 0;
}