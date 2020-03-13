#include<bits/stdc++.h>

using namespace std;
typedef struct _arr{
	float val;
	bool used;
}arr;

int main()
{
	int Num_Test,iter;
	ifstream fin;
	fin.open("war.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,i,j,idx,dw=0,w=0;
		fin>>N;
		//float Naomi[N],Ken[N];
		vector<arr> Naomi(N);
		vector<arr> Ken(N);
		for(i=0;i<N;i++){
			fin>>Naomi[i].val;
			Naomi[i].used=false;
		}
		for(i=0;i<N;i++){
			fin>>Ken[i].val;
			Ken[i].used=false;
		}
		for(i=0;i<N;i++){
			for(j=0;j<N-1;j++){
				if(Naomi[j].val>Naomi[j+1].val){
					swap(Naomi[j].val,Naomi[j+1].val);
				}
				if(Ken[j].val>Ken[j+1].val){
					swap(Ken[j].val,Ken[j+1].val);
				}
			}
		}
		//WAR
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(Naomi[i].val<Ken[j].val && !Ken[j].used){
					Naomi[i].used=true;
					Ken[j].used=true;
					break;
				}
			}
			if(!Naomi[i].used)
				break;
		}
		w=N-i;
		//Deicitful War
		for(i=0;i<N;i++){
			Naomi[i].used=false;
			Ken[i].used=false;
		}
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(Naomi[i].val>Ken[j].val && !Ken[j].used){
					Naomi[i].used=Ken[j].used=true;
					dw++;
					break;
				}
			}
		}
		cout<<"CASE #"<<iter+1<<":\t"<<dw<<"\t"<<w<<endl;
	}
	return 0;
}