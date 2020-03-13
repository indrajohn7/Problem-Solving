#include<bits/stdc++.h>

using namespace std;
typedef pair<char[20],char[20]> pcc; 

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("fakers_in.in");
	fin>>Num_Test;
	ofstream fout;
	fout.open("fakers_out.in");
	for(iter=0;iter<Num_Test;iter++){
		int N,count=0;
		vector<pcc> v;
		fin>>N;
		for(int i=0;i<N;i++){
			char* str1=new char[20];
			fin>>str1;
			char* str2=new char[20];
			fin>>str2;
			pair<char*,char*> p=make_pair(str1,str2);
			v.push_back(p);
		}
		for(int i=0;i<N;i++){
			
		}
	}
	return 0;
}