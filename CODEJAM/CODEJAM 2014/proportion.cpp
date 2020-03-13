#include<bits/stdc++.h>

using namespace std;

typedef struct _sub{
	float ratio;
	int idx;
}sub;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("proportion.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,i,j,k,l,min,Idx,flag=0;
		float count0,count1;
		float percent;
		fin>>N>>percent;
		char* stream =new char[N];
		fin>>stream;
		vector<sub> S;
		i=0;l=0;
		while(i<N){
			for(j=i;j<N;j++){
				count1=count0=flag=0;
				for(k=i;k<=j;k++){
					if(stream[k]=='1')
						count1++;
					else
						count0++;
				}
				sub s;
				s.ratio=(float)(count1/(count1+count0));
				s.ratio=(abs)(s.ratio-percent);
				s.idx=i;
				if(s.ratio<=0.00001){
					flag=1;
					Idx=i;
					break;
				}					
				S.push_back(s);
			}
			if(flag==1)
				break;
			i++;
		}
		if(flag!=1){
		for(i=0;i<S.size();i++){
			for(j=0;j<(S.size())-1;j++){
				if(S[j].ratio>S[j+1].ratio){
					sub s;
					s=S[j];
					S[j]=S[j+1];
					S[j+1]=s;
				}
			}
		}
		min=S[0].idx;
		for(i=1;i<S.size();i++){
			if(S[i].ratio==S[0].ratio){
				if(min>S[i].idx)
					min=S[i].idx;
			}
			else
				break;
		}
		}
		else
			min=Idx;
		cout<<"CASE #"<<iter+1<<":\t"<<min<<endl;
	}
	return 0;
}