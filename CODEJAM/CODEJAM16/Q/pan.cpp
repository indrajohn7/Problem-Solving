#include<bits/stdc++.h>

using namespace std;

#define size 100

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("pan_large.in");
	fin>>Num_Test;
	ofstream fout;
	fout.open("out_large.in");
	for(iter=0;iter<Num_Test;iter++){
		char* str=new char[size];
		fin>>str;
		int count=0,time=0;
		while(count!=strlen(str)){
			char first=str[0];
			count=0;
			for(int i=0;i<strlen(str);i++){
				if(str[i]=='+')
					count++;
			}
			if(count==strlen(str))
				break;
			else if(count==0){
				time+=1;
				break;
			}
			else{
				for(int i=0;i<strlen(str);i++){
					if(str[i]!=first){
						for(int j=0;j<i;j++){
							if(str[j]=='-')
								str[j]='+';
							else
								str[j]='-';
						}
						time++;
						break;
					}
				}
			}
		}
		fout<<"CASE #"<<iter+1<<": "<<time<<endl;
	}
	return 0;
}