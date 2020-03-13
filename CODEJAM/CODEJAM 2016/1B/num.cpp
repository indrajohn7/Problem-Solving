#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("a.in");
	ofstream fout;
	fout.open("a2.in");
//	freopen("a1.in","w",stdout);
	fin>>Num_Test;
	const char stream[10][10]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
	const char order[10]={'Z','W','G','H','U','X','F','V','O','I'};
	const int ord[10]={0,2,8,3,4,6,5,7,1,9};
	for(iter=0;iter<Num_Test;iter++){
		list<char> str;
		char* s=new char[2001];
		fin>>s;
		for(int i=0;i<strlen(s);i++)
			str.push_back(s[i]);
		vector<int> v;
	//	while(str.size()!=0){
		for(int i=0;i<10;i++){
			int count=0;
			for(list<char>::iterator it=str.begin();it!=str.end();it++){
				if(*it==order[i]){
					it=str.erase(it);
					--it;
					//it++;
					count++;
					v.push_back(ord[i]);
				}			
			}
			while(count!=0){
				for(int k=0;k<strlen(stream[ord[i]]);k++ ){
					if(stream[ord[i]][k]!=order[i]){
						for(list<char>::iterator it=str.begin();it!=str.end();it++){
							if(*it==stream[ord[i]][k]){
								it=str.erase(it);
								--it;
								break;
							}			
						}
					}
				}
				count--;
			}
		}
		sort(v.begin(),v.end());
		fout<<"Case #"<<iter+1<<": ";
		cout<<"Case #"<<iter+1<<": ";
		for(int i=0;i<v.size();i++){
			fout<<v[i];
			cout<<v[i];
		}
	fout<<endl;
	cout<<endl;
	}
	return 0;
}