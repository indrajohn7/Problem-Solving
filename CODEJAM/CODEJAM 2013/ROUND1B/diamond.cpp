#include<bits/stdc++.h>

using namespace std;
#define SIZE 1500
#define sum(x) ((x)*((x)+1))/2

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("diamond.in");
	fin>>Num_Test;
	ofstream fout;
	fout.open("diamond.out");
	for(iter=0;iter<Num_Test;iter++){
		int N,X,Y,i,j,k,x_last,y_last,num;
		float prob=0,p=0.5,val;
		fin>>N>>X>>Y;
		for(i=0;i<N;i++){
			if(sum((2*i)+1)>=N)
				break;
		}
		k=Y+1;
		if(sum((2*i)+1)==N && abs(X)+abs(Y)<=(2*i))
			prob=1;
	    else if(abs(X)+abs(Y)<(2*i))
			prob=1;
		else if(abs(X)+abs(Y)==(2*i)){
			x_last=2*(i-1);
			y_last=2*(i-1);
			num=sum((2*(i-1))+1);

				if(N>= num+2*i+1+Y){
					prob=1;
				//	break;
				}
				else if(N>=num+1+Y){
					if(Y==2*i){
						if(N==sum((2*i)+1))
							prob==1;
						else
							prob=0;
					}
					else{
					int it=(num+1+Y);
					while(it<=N){//(num+Y<N){
						val=1;
						for(j=1;j<=k;j++){
						    val*=p;
						}
						prob+=val;
						k++;
						it++;
						//num++;
					}
					}
				}
				else {
					prob=0;
					//break;
				}
			
		}
		else{
			prob=0;
		}
		fout<<"Case #"<<iter+1<<": "<<prob<<endl;
	}
}