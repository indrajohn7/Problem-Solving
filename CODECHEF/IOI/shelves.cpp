#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("shelves.in","r",stdin);
	int N,K;
	cin>>N>>K;
	int* f=new int[N];
	int* s=new int[N];
	for(int i=0;i<N;i++)
		cin>>f[i];
	for(int i=0;i<N;i++)
		cin>>s[i];
	sort(f,f+N);
	sort(s,s+N);
	int skew=f[N-1]+s[N-1];
	for(int i=0;i<K;i++){
		if(f[N-1]>s[N-1]){
			if(f[N-2]<s[N-2]){
				if(f[N-1]>s[0])
					swap(f[N-1],s[0]);
				else if(f[N-1]<s[0] && s[N-1]>f[0])
					swap(s[N-1],f[0]);
			}
			else{
				if(s[N-1]>f[0])
					swap(s[N-1],f[0]);
				else if(s[N-1]<f[0] && f[N-1]>s[0])
					swap(f[N-1],s[0]);
			}
		}
		else if(f[N-1]<=s[N-1]){
			if(s[N-2]<f[N-2]){
				if(s[N-1]>f[0])
					swap(s[N-1],f[0]);
				else if(s[N-1]<f[0] && f[N-1]>s[0])
					swap(f[N-1],s[0]);
			}
			else{
				if(f[N-1]>s[0])
					swap(f[N-1],s[0]);
				else if(f[N-1]<s[0] && s[N-1]>f[0])
					swap(s[N-1],f[0]);
			}
		}
		sort(f,f+N);
		sort(s,s+N);
		int dummy=f[N-1]+s[N-1];
		if(dummy<skew)
			skew=dummy;
	}
	cout<<skew;
	return 0;
}