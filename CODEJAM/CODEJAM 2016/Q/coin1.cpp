#include<bits/stdc++.h>

using namespace std;

#define size 50

long long int getvalue(char temp[size],int n)
{
	long long int res=0;
	char* t=new char[16];
	strncpy(t,temp,16);
	for(int i=0;i<strlen(t);i++){
		res+=(temp[strlen(t)-i-1]-'0')*pow(n,i);
	}
	return res;
}


bool isprime(int n,int r, int c, long long int divisor[50][9])
{
	for(int i=2;i<=n/2;i++){
		if((n%i)==0){
			divisor[r][c]=i;
			return false;
		}
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
		long long int val[J][9],k,divisor[J][9];
	/*	long long int** divisor = new long long int*[J];
	//	for(i=0;i<9;i++)
	//		divisor[i]=new long long int[9];
		for(i=0;i<J;i++){
			for(j=0;j<9;j++)
				divisor[i][j]=0;
		}*/
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
		//temp[]
		while(count!=J){			
			bool valid=true;			
			for(i=0;i<9;i++){
				val[count][i]=getvalue(temp,i+2);
				if(isprime(val[count][i],count,i,divisor)==true){
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
		
		fout<<"Case #"<<iter+1<<":"<<endl;
		for(i=0;i<J;i++){
			for(int l=0;l<N;l++){
				fout<<stream[i][l];
				cout<<stream[i][l];
			}
		//	cout<<" ";
		//	fout<<" ";
			for(j=0;j<9;j++){
				fout<<" "<<divisor[i][j];
				cout<<" "<<divisor[i][j];
			}
			fout<<endl;
			cout<<"\n";
		}
	}
	//fout.close("out_small.in");
	return 0;
}
