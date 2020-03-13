#include<bits/stdc++.h>

using namespace std;

int main()
{
	int iter,Num_test;
	ifstream fin;
	fin.open("rata.in");
	fin>>Num_test;
	for(iter=0;iter<Num_test;iter++){
		int N,P;
		fin>>N>>P;
		int* serving=new int[N];
		for(int i=0;i<N;i++)
			fin>>serving[i];
		int** packets=new int*[N];
		for(int i=0;i<N;i++)
			packets[i]=new int[P];
		for(int i=0;i<N;i++){
			for(int j=0;j<P;j++)
				fin>>packets[i][j];
		}
		
		int** dummy=new int*[N];
		for(int i=0;i<N;i++){
			dummy[i]=new int[P];
			memset(dummy[i],0,4*P);
		}
		
		int kits=0;
		
		for(int j=0;j<P;j++){
			int dum=0,flag=0;
			int pack=packets[0][j]/serving[0];
			if(serving[0]*pack<packets[0][j]){
				if((packets[0][j] <= (pack*serving[0]*1.1))){
					pack=pack;
					if(N==1)
						flag=1;
				}/*else if((packets[0][j] <= ((pack+1)*serving[0]*0.9)) && ){
					pack=pack+1;
					if(N==1)
						flag=1;
				}*/else if((packets[0][j] >= ((pack+1)*serving[0]*0.9)) &&(packets[0][j] < ((pack+1)*serving[0])) ){
					pack+=1;
					if(N==1)
						flag=1;
				}else{
					continue;
				}
			}else{
				if(N==1)
					flag=1;
			}
			dummy[0][j]=1;
				for(int i=1;i<N;i++){
					flag=0;
					for(int k=0;k<P;k++){
						if(dummy[i][k]==0 && packets[i][k]>=(pack*serving[i]*0.9) && packets[i][k]<=(pack*serving[i]*1.1)){
							flag=1;
							dum++;
							dummy[i][k]=1;
							break;
						}
							
					}
					if(flag==1)
						continue;
					else
						break;
				}
				if(flag==1 && dum==N-1)
					kits++;
				
			
		}
		cout<<"Case #"<<iter+1<<": "<<kits<<endl;
		
	}
	return 0;
}