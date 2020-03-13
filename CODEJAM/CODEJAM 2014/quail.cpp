#include<bits/stdc++.h>

using namespace std;

typedef struct _pos{
	float P;
	float S;
}position;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("quail.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int Y,N,i,j,temp;
		float t_n=0,t_p=0;
		fin>>Y>>N;
		vector<position> pos(N);
		for(i=0;i<N;i++)
		    fin>>pos[i].P;
		for(i=0;i<N;i++)
			fin>>pos[i].S;
		//SORT
		for(i=0;i<N;i++){
			for(j=0;j<N-1;j++){
				if(pos[j].P>pos[j+1].P){
					position p;
					p=pos[j];
					pos[j]=pos[j+1];
					pos[j+1]=p;
				}
			}
		}
		//Negative co-ordinate
		for(i=0;i<N;i++){
			if(pos[i].P<0){
				if((abs(pos[i].P)/(Y-pos[i].S)) > t_n)
					t_n=(abs(pos[i].P)/(Y-pos[i].S));
				temp=i;
			}
			else 
				break;
		}
		//Positive Co-ordinate
		if(t_n>0){
			for(i=temp+1;i<N;i++){
				pos[i].P+=pos[i].S*2*t_n;
			}
		}
		for(i=temp+1;i<N;i++){
			if(pos[i].P>0){
				if((abs(pos[i].P)/(Y-pos[i].S)) > t_p)
					t_p=(abs(pos[i].P)/(Y-pos[i].S));
			}
		}
		if(t_p>0)
		    cout<<"CASE #"<<iter+1<<":\t"<<2*t_n+t_p<<endl;
	    else
		    cout<<"CASE #"<<iter+1<<":\t"<<t_n<<endl;
	}
	return 0;
}