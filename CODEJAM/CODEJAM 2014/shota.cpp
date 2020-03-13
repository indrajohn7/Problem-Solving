#include<bits/stdc++.h>

using namespace std;

typedef struct _str{
	char val[100];
	bool used;
}str;
int main()
{
	int Num_Test,iter;
	ifstream fin;
	//fin.open("shota.in");
	//fin.open("shota_large.in");
	fin.open("shota_small.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,L,i,j,count=0;
		long long int num;
		fin>>N>>L;
		char* str1=new char[L];
	//	char avl[N][L],req[N][L];
	    vector<str> avl(N);
		vector<str> req(N);
 		for(i=0;i<N;i++){
			fin>>str1;
			memcpy(avl[i].val,str1,L);
			//sprintf(avl[i].val,"%lld",num);
			avl[i].used=false;
		}
		for(i=0;i<N;i++){
			fin>>str1;
			memcpy(req[i].val,str1,L);
		//	sprintf(req[i].val,"%lld",num);
			req[i].used=false;
	    }
		for(i=-1;i<L;i++){
			count=0;
			if(i!=-1){
				for(j=0;j<N;j++){
					if(avl[j].val[L-(i+1)]=='0')
						avl[j].val[L-(i+1)]='1';
					else
						avl[j].val[L-(i+1)]='0';
					avl[j].used=false;
				}
			}
			for(j=0;j<N;j++){
				for(int k=0;k<N;k++){
					if(strcmp(req[j].val,avl[k].val)==0 && avl[k].used==false){
						avl[k].used==true;
						count++;
						break;
					}
				}
			}
			if(count==N)
				break;
			else{
				if(i!=-1){
				for(j=0;j<N;j++){
					if(avl[j].val[L-(i+1)]=='0')
						avl[j].val[L-(i+1)]='1';
					else
						avl[j].val[L-(i+1)]='0';
					avl[j].used=false;
				}
			}
			}
		}
		cout<<"CASE #"<<iter+1<<":\t";
		if(count==N)
			cout<<i+1<<endl;
		else
			cout<<"NOT POSSIBLE!\n";
	}
	return 0;
}
