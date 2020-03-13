#include<bits/stdc++.h>

using namespace std;

struct circle{
	int val;
	//int left;
	int right;
	circle(int v,int r)
	{
		val=v;
		//left=l;
		right=r;
	}
};


int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("bff.in");
	fin>>Num_Test;
	ofstream fout;
	fout.open("bff.out");
	for(iter=0;iter<Num_Test;iter++){
		int N,j,k,i;
		fin>>N;
		int a[N];
		for(i=0;i<N;i++)
			fin>>a[i];
		vector<circle*> res;
		for(i=0;i<N;i++){			
			vector<circle*> temp;
			int list[100],max=0;
			k=0;
			for(j=i+1;j<N;j++){
				if(a[j]==i)
					list[k++]=a[j];
			}
			if(k==0)
				continue;
			else{
				int flag=0;
				circle* c=new circle(i,a[i]);
				temp.push_back(c);
				l=a[i];
				k=a[i];
				while(k!=temp.front() &&  k!=l && flag!=k){
					circle* c=new circle(l,a[l]);
				    temp.push_back(c);
					flag=l;
					l=a[l];
				    k=a[l];
					//i++;
				}
				while(1){
				for(j=0;j<N;i++){
					if(a[j]==l && j!=k){
						buff=1;
						circle* c=new circle(j,a[j]);
						temp.push_back(c);
						break;
					}
				}
				}
			}
		}
	}
}