#include<bits/stdc++.h>

using namespace std;

typedef pair<char*,int> pic;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("b.in");
	ofstream fout;
	fout.open("b1.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		char* coder=new char[20];
		char* jammer=new char[20];
		fin>>coder>>jammer;
		//Scanner1
		for(i=0;i<strlen(coder);i++){
			if(isdigit(coder[i]) && jammer[i]=='?')
				jammer[i]=coder[i];
			else if(isdigit(jammer[i]) && coder[i]=='?')
				coder[i]=jammer[i];
		}
		int ch_c,ch_j;
		ch_c=ch_j=0;
		for(i=0;i<strlen(coder);i++){
			if(coder[i]=='?')
				ch_c++;
			if(jammer[i]=='?')
				ch_j++;
		}
		char dyn_c[ch_c]={'0'};
		char dyn_j[ch_j]={'0'};
		vector<pic> v;
		while(dyn_c[0]!='9'){
			
		}
	}
	return 0;
}