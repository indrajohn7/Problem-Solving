#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_Test;
	freopen("key.in","r",stdin);
	cin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int n,m,c;
		cin>>n>>m>>c;
		int count=0;
		for(int i=1;i<=sqrt(c);i++){
			if(c%i==0){
				int num,deno;
				num=c/i;
				deno=i;
				if(num==deno)
					count++;
				else{
					if(num<=n && deno<=m)
						count++;
					if(num<=m && deno<=n)
						count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}