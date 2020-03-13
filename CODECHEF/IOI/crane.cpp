#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("crane.in","r",stdin);
	int N,H,move,pos=0;
	bool isbox=false;
	cin>>N>>H;
	int* arr=new int[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];
	while(cin>>move){
		if(move!=0){
			if(move==1){
				if(pos!=0)
					pos-=1;
			}
			else if(move==2){
				if(pos!=N-1)
					pos+=1;
			}
			else if(move==3){
				if(isbox==false && arr[pos]!=0){
					isbox=true;
					arr[pos]-=1;
				}
			}
			else if(move==4){
				if(isbox==true && arr[pos]<H){
					arr[pos]+=1;
					isbox=false;
				}
			}
		}
		else
			break;
	}
	for(int i=0;i<N;i++)
		cout<<arr[i]<<" ";
	return 0;
}