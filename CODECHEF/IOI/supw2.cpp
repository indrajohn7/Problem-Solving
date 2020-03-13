#include<bits/stdc++.h>

using namespace std;

#define cal_min(A,N) (A[N].first<A[N+1].first)?((A[N].first<A[N+2].first)? N:(N+2)):((A[N+1].first<A[N+2].first)?(N+1):(N+2))

typedef pair<int,bool> pib;


int main()
{
	freopen("supw.in","r",stdin);
	int N,time=0,work=0,first,second,third,days=0;
	cin>>N;
	vector<pib> vp;
	int* arr=new int[N];
	for(int i=0;i<N;i++){
		int t;
		cin>>t;
		vp.push_back(make_pair(t,false));
	}
	vector<int> v;
	int last_pos=-1,curr_pos=-1,last_val=0,curr_val=0;
	for(int i=0;i<N-2;i++){
		bool selected=false;
	//	if(!vp[i].second && !vp[i+1].second && !vp[i+2].second){
			int t=cal_min(vp,i);
			if(i>0){
				if(t-last_pos<=3){  //changed to max
					if(t-last_pos!=0){
						int tmp=(t==i)?(vp[i+1].first>vp[i+2].first)?(i+2):(i+1):(t==i+1)?(vp[i].first>vp[i+2].first)?(i+2):i:(vp[i].first>vp[i+1].first)?(i+1):i;
						if((vp[last_pos].first+vp[t].first) >=  vp[tmp].first){
							if(v.size()>=2){
								if(tmp-v[v.size()-2]<=3){
									v.erase(v.end()-1);
									v.push_back(tmp);
									vp[last_pos].second=false;
									last_pos=tmp;
									vp[last_pos].second=true;
									last_val=vp[last_pos].first;
								}
								else if(!(i==N-2 && (!vp[i].second && !vp[i+1].second && !vp[i+2].second))){ //changed
									vp[t].second=true;
									v.push_back(t);
									last_pos=t;
									last_val=vp[t].first;
								}
							}
							else{
								if(tmp<3){
									v.erase(v.end()-1);
									v.push_back(tmp);
									vp[last_pos].second=false;
									last_pos=tmp;
									vp[last_pos].second=true;
									last_val=vp[last_pos].first;
								}
								else if(!(i==N-2 && (!vp[i].second && !vp[i+1].second && !vp[i+2].second))){
									vp[t].second=true;
									v.push_back(t);
									last_pos=t;
									last_val=vp[t].first;
								}
							}
						}
						else if(!(i==N-2 && (!vp[i].second && !vp[i+1].second && !vp[i+2].second))){
							vp[t].second=true;
							v.push_back(t);
							last_pos=t;
							last_val=vp[t].first;
						}
					}
				}
				else if(!(i==N-2 && (!vp[i].second && !vp[i+1].second && !vp[i+2].second))){
					vp[t].second=true;
					v.push_back(t);
					last_pos=t;
					last_val=vp[t].first;
				}
			}
			else {
				if(!vp[t].second)
				v.push_back(t);
				last_pos=t;
				last_val=vp[t].first;
				vp[t].second=true;
			}
		//}
	}
	int sum=0;
	for(int i=0;i<v.size();i++)
		sum+=vp[v[i]].first;
	cout<<sum;
	return 0;
}