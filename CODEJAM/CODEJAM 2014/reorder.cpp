#include<bits/stdc++h>

using namespcae std;

int fact(int n)
{
	if(n==0 || n==1)
		return 1;
	else 
		return n*fact(n-1);
}

int main()
{
	int iter, Num_Test;
	ifstream fin;
	fin.open("reorder.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,i,j,k,l,count=0,proceed=0;
		fin>>N;
		char str[N][10];
		for(i=0;i<N;i++){
			char* temp=new char[10];
			fin>>temp;
			strcpy(str[i],temp);
		}
		int alpha[26]={0};
		for(i=0;i<N;i++){
			for(j=0;str[i][j]!='\0';j++){
				alpha[str[i][j]-'a']++;
			}
		}
		for(i=0;i<26;i++){
			if(alpha[i]>1)
				proceed=1;
		}
		if(proceed==0)
			cout<<"CASE #"<<iter+1<<":\t"<<fact(N)<<endl;
		else{
			
		}
	}
}