#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter, Num_Test;
	ifstream fin;
	fin.open("word.in");
	fin>>Num_Test;
	ofstream fout;
	fout.open("word.out");
	for(iter=0;iter<Num_Test;iter++){
		char a[1001];
		vector<char> b;
		fin>>a;
		int i=0;
		b.insert(b.begin(),a[i++]);
		vector<char>::iterator it;
		while(i!=strlen(a)){
			
			int flag=0;
			for(it=b.begin();it!=b.end();it++){
				if(*it>a[i]){
					flag=1;
				}
			}
			if(flag==1){
				b.push_back(a[i]);
			}
			else{
				b.insert(b.begin(),a[i]);
			}
			i++;
		}
		fout<<"Case #"<<iter+1<<": ";
		for(it=b.begin();it!=b.end();it++)
			fout<<*it;
		fout<<endl;
	}
	return 0;
}