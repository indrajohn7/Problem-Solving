#include<bits/stdc++.h>

using namespace std;

typedef struct _wash{
	int time;
	int elapsed;
	bool state;
	vector<int> v;
	_wash(int t,int e,bool b)
	{
		time=t;
		elapsed=e;
		state=b;
	}
}wash;

typedef struct _load{
	int wash_m;
	int dry_m;
	bool wash;
	bool dry;
	_load(int w,int d,bool w,bool d)
	{
		wash_m=w;
		dry_m=d;
		wash=w;
		dry=d;
	}
}load;

typedef struct _dry{
	int time;
	int elapsed;
	bool state;
	_dry(int t,int e,bool b)
	{
		time=t;
		elapsed=e;
		state=b;
	}
}dry;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("laundry.in");
	fin>>Num_Test;
	vector<wash> v_w;
	vector<load> v_l;
	vector<dry> v_d;
	int* arr=new int[N];
	for(iter=0;iter<Num_Test;iter++){
		int L,N,M,D;
		fin>>L>>N>>M>>D;
		for(int i=0;i<N;i++){
			int t;
			fin>>t;
			arr[i]=t;
		}
		sort(arr,arr+N);
		for(int i=0;i<N;i++){
			wash w=new wash(arr[i],0,false);
			v_w.push_back(w);
		}
		for(int i=0;i<L;i++){
			load l=new load(-1,-1,false,false);
			v_l.push_back(l);
		}
		for(int i=0;i<M;i++){
			dry d=new dry(D,0,false);
			v_d.push_back(d);
		}
		int wash_count,dry_count,total,timelap;
		wash_count=dry_count=total=timelap=0;
		while(timelap){
			if(wash_count!=L){
				for(int i=0;i<N;i++){
						if(v_w[i].state){
							if(v_w[i].elapsed==v_w[i].time){
								v_w[i].elapsed=0;
								v_w[i].state=false;
								--i;
							}else{
								v_w[i].elapsed+=1;
							}
						}else{
							int flag=0;
							for(int j=0;j<i;j++){
								if((2*v_w[j].time-v_w[j].elapsed)<v_w[i].time){
									flag=1;
									break;
								}
							}
							if(!flag){
								v_w[i].state=true;
								wash_count++;
							//	break;
							}
						}
				}
				timelap++;
			}else{
				break;
			}
		}
		int dried=(timelap/D)*M;
		if(dried>L){
			timelap+=D;
		}else{
			
		}
	}
}