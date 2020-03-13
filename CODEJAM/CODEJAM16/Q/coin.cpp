#include<bits/stdc++.h>

using namespace std;

#define size 50

long long int getvalue(char temp[size],int n)
{
	long long int res=0;
	for(int i=0;i<strlen(temp);i++){
		res+=(temp[strlen(temp)-i-1]-'0')*pow(n,i);
	}
	return res;
}


bool isprime(int n)
{
	for(int i=2;i<=n/2;i++){
		if((n%i)==0)
			return false;
	}
	return true;
}

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("coin_small.in");
	fin>>Num_Test;
	ofstream fout;
	fout.open("out_small.in");
	for(iter=0;iter<Num_Test;iter++){
		int N,J,i,j,count=0;
		fin>>N;
		fin>>J;
		long long int val[J][9],k;
		char* str=new char[N];
		for(i=0;i<N;i++){
			if(i==0 || i==N-1)
				str[i]='1';
			else
				str[i]='0';
		}
		char temp[N],stream[J][N];
		for(i=0;i<J;i++){
			for(j=0;j<N;j++)
				stream[i][j]=0;
		}
		strncpy(temp,str,strlen(str));
		while(count!=J){			
			bool valid=true;			
			for(i=0;i<9;i++){
				val[count][i]=getvalue(temp,i+2);
				if(isprime(val[count][i])==true){
					valid=false;
					break;
				}
			}
			if(valid==false){
				int t;
					while(1){
						t=rand()%(strlen(str)-1);
						if(t!=0)
							break;
					}
					if(t!=0){
						(temp[t]=='0')?temp[t]='1' : temp[t]='0';
					}
			}
			else{
				bool present=false;
				for(j=0;j<count;j++){
					if(strncmp(stream[j],temp,strlen(temp))==0){
						present=true;
						break;
					}
				}
				if(present==false){
					strncpy(stream[count],temp,strlen(temp));
					count++;
				}
				else{
					int t;
					while(1){
						t=rand()%(strlen(str)-1);
						if(t!=0)
							break;
					}
					if(t!=0){
						(temp[t]=='0')?temp[t]='1' : temp[t]='0';
					}
				}
			}
		}
		
		fout<<"CASE #"<<iter+1<<":"<<endl;
		for(i=0;i<J;i++){
			for(int l=0;l<N;l++){
				fout<<stream[i][l];
				cout<<stream[i][l];
			}
			cout<<" ";
			fout<<" ";
			for(j=0;j<9;j++){
				for(k=2;k<val[i][j];k++){
					if(val[i][j]%k==0)
						break;
				}
				fout<<k<<" ";
				cout<<k<<" ";
			}
			fout<<endl;
			cout<<"\n";
		}
	}
	//fout.close("out_small.in");
	return 0;
}