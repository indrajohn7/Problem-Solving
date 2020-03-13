#include<bits/stdc++.h>

using namespace std;
#define six pow(10,6)

int main()
{
	int iter, Num_test;
	ifstream fin;
	fin.open("a.in");
	ofstream fout;
	fout.open("a.txt");
	fin>>Num_test;
	for(iter=0;iter<Num_test;iter++){
		int N;
		long double D;
		fin>>D>>N;
		typedef pair<long double,long double> pii;
		vector<pii> vec;
		for(int i=0;i<N;i++){
			long double a,b;
			fin>>a>>b;
			vec.push_back(make_pair(a,b));
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N-1;j++){
				if(vec[j].first>vec[j+1].first){
						pii p;
						p=vec[j];
						vec[j]=vec[j+1];
						vec[j+1]=p;
				}
			}
		}
		typedef long double llf;
		long double speed=0;
		if(vec.size()==1){
			llf time=(llf)((D-vec[0].first)/vec[0].second);
			speed=D/time;
		}else{
			float time;
			if(vec[1].second>=vec[0].second){
				time=(llf)((llf)(D-vec[0].first)/vec[0].second);
				speed=D/time;
			}else{
				llf t1;
				t1=(llf)((vec[1].first-vec[0].first)/(vec[0].second-vec[1].second));
				if((vec[0].first+(t1*vec[0].second))>=D){
					time=(llf)((D-vec[0].first)/vec[0].second);
					speed=D/time;
				}else{
					llf des=(llf)(vec[0].first+(llf)(t1*vec[0].second));
					time=t1+(llf)((D-des)/vec[1].second);
					speed=D/time;
				}
			}
			
		}
		
		speed=speed*six;
		
		fout<<"Case #"<<iter+1<<": "<<setprecision(6)<<(speed/six)<<endl;
		//printf("%.6f\n",speed);
	}
	return 0;
}