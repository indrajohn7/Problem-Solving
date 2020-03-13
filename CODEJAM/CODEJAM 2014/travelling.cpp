///////////////////////////////////////////////////////////////
//This code is not optimized and has to be modified with the implementation of Graph Traversal(PRIM's ALGO)
//////////////////////////////////////////////////////////////////

#include<bits/stdc++.h>

using namespace std;
typedef struct _postal{
	int zip;
	int idx;
}postal;


int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("travelling.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,M,i,count=0;
		fin>>N>>M;
	//	vector<postal> post(N);
	    int post[N];
		for(i=0;i<N;i++)
			fin>>post[i];
		//SORT
		/*
		for(i=0;i<N;i++){
			if(post[i].zip>post[i+1].zip){
				vector<postal> p;
				p=post[i];
				post[i]=post[i+1];
				post[i+1]=p;
			}
		}
		*/
		int min=111111,idx=N+1;
		for(i=0;i<N;i++){
			if(post[i]<min){
				min=post[i];
				idx=i+1;
			}
		}
		int flights[M][2],j,k;
		for(i=0;i<M;i++){
			for(j=0;j<2;j++)
				fin>>flights[i][j];
		}
		//CALCULATE
		/*
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				for(k=0;k<2;k++){
					if(post[i].idx==flights[j][k]){
						
					}
				}
			}
		}
		*/
		char str[5*N],buff[6];
		sprintf(buff,"%d",min);
		strcpy(str,buff); //,strlen(buff));
		int visited[50]={0},m=0,nodes[50]={0};
		visited[idx-1]=idx;
		nodes[m++]=idx;
		count++;
		while(count!=N){
			int temp[50]={0};
			int l=0,flag=0;
			min=111111;
			for(j=0;j<M;j++){
				for(k=0;k<2;k++){
					if(flights[j][k]==idx && !(visited[flights[j][k^1]-1]==flights[j][k^1])){
						if(k==0)
							temp[l++]=flights[j][1];
						else
							temp[l++]=flights[j][0];
						flag=1;
					}
				}
			}
			if(flag==1){
			for(j=0;j<l;j++){
				if(post[temp[j]-1]<min){
					min=post[temp[j]-1];
					idx=temp[j];
				}
			}
			if(visited[idx-1]!=idx){
				sprintf(buff,"%d",min);
				strcat(str,buff);
				visited[idx-1]=idx;
				nodes[m++]=idx;
				count++;
			}
			}
			else{
				idx=nodes[--m];
			}
		}
		cout<<"CASE #"<<iter+1<<":\t"<<str<<endl;
	}
	return 0;
}