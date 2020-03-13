#include<bits/stdc++.h>

using namespace std;

typedef struct _out{
	int jacket;
	int pant;
	int shirt;
}out;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("outfit.in");
	fin>>Num_Test;
	ofstream fout;
	fout.open("out.txt");
	for(iter=0;iter<Num_Test;iter++){
		int J,P,S,K,s,j,k,p;
		fin>>J>>P>>S>>K;
		vector<out> v;
		s=p=j=1;
		while(s<=S){
			j=p=1;
			while(p<=P){
			bool duplicate=false;
			int js=0,jp=0,ps=0;
			for(int i=0;i<v.size();i++){
				if(v[i].jacket==j && v[i].shirt==s && v[i].pant==p){
					duplicate=true;
					break;
				}
				if(v[i].jacket==j && v[i].shirt==s)
					js++;
				if(v[i].jacket==j && v[i].pant==p)
					jp++;
				if(v[i].shirt==s && v[i].pant==p)
					ps++;
			}
			if(!duplicate && (js+1)<=K && (ps+1)<=K && (jp+1)<=K){
				out o;
				o.jacket=j;
				o.pant=p;
				o.shirt=s;
				v.push_back(o);
			}
			if(j<J)
				j++;
			else{ 
				p++;
				j=1;
			}
			}
			s++;
		}
		fout<<"Case #"<<iter+1<<": "<<v.size()<<endl;
	/*	for(int i=0;i<v.size();i++){
			fout<<v[i].jacket<<" ";
			fout<<v[i].pant<<" ";
			fout<<v[i].shirt<<endl;
		} */
	}
	return 0;
}