#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("battle.in");
	fin>>Num_Test;
	ofstream fout;
	fout.open("battle.txt1");
	for(iter=0;iter<Num_Test;iter++){
		int R,C,W,ans=0,ans2=1;
		fin>>R>>C>>W;
		if(W==C)
			ans=R-1+W;
		else{
			ans=R*(C/W)+W-1;
			if(C%W)
				++ans;
		}
		fout<<"Case #"<<iter+1<<": "<<ans<<endl;
	}
	return 0;
}