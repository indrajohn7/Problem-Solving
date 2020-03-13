#include<bits/stdc++.h>
//This soluryion will work for N*N solution
using namespace std;

struct LU{
	int** lower;
	int** upper;
	LU(int R,int C)
	{
		lower=new int*[R];
		for(int i=1;i<=R;i++)
			lower[i]=new int[C];
		upper=new int*[R];
		for(int i=1;i<=R;i++)
			upper[i]=new int[C];
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++){
				lower[i][j]=0;
				upper[i][j]=0;
			}
		}
	}
};

LU* LU_Decompose(int** A,int R,int C)
{
	int i,j,k;
	LU* lu=new LU(R,C);
	for(i=1;i<=R;i++){
	    lu->upper[i][i]=A[i][i];
		lu->lower[i][i]=1;
		for(j=i+1;j<=R;j++){
			lu->lower[j][i]=A[j][i]/lu->upper[i][i];
			lu->upper[i][j]=A[i][j];
		}
		for(j=i+1;j<=R;j++){
			for(k=i+1;k<=C;k++)
				A[j][k]=A[j][k]-lu->lower[j][i]*lu->upper[i][k];
		}
	}
	return lu;
}

void LUP_Solve(LU* lu,int pi[100],int* B,int R,int C)
{
	int i,j,Y[R];
	float X[R];
	for(i=1;i<=R;i++){
		int sum=0;
		for(j=1;j<=i-1;j++)
			sum+=lu->lower[i][j]*Y[j];
		Y[i]=B[i]-sum;
	}
	for(i=1;i<=R;i++)
		cout<<Y[i]<<"\t";
	cout<<endl;
	for(i=R;i>=1;i--){
		int sum=0;
		for(j=i+1;j<=R;j++)
			sum+=lu->upper[i][j]*X[j];
		X[i]=(float)(Y[i]-sum)/lu->upper[i][i];
	}
	cout<<"ANSWER::\n";
	for(i=1;i<=R;i++){
		cout<<"X["<<i<<"]\t:"<<X[i]<<endl;
	}
}


int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("smooth.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,K,i,j;
		
		//Data extraction starts
		fin>>N>>K;
		int S[N-K+2],Sum[N-K+2],B[N-K+2];
		int** A=new int*[N-K+2];
		for(i=1;i<=N-K+1;i++)
			A[i]=new int[N+1];
		for(i=1;i<=N-K+1;i++){
			fin>>Sum[i];
			S[i]=Sum[i]/K;
		}
		for(i=1;i<=N-K+1;i++){
			for(j=i;j<=i+K-1;j++){
				B[i]=S[i]*(K-1);
				A[i][j]=1;
			}
		}
		
		//Data extraction ends
		LU* lu=new LU(N-K+1,N);
		lu=LU_Decompose(A,N-K+1,N);
		cout<<"LOWER TRIANGULAR MATRIX:\n";
		for(i=1;i<=N-K+1;i++){
			for(j=1;j<=N;j++)
				cout<<lu->lower[i][j]<<"\t";
			cout<<endl<<endl;
		}
		cout<<"UPPER TRIANGULAR MATRIX:\n";
		for(i=1;i<=N-K+1;i++){
			for(j=1;j<=N;j++)
				cout<<lu->upper[i][j]<<"\t";
			cout<<endl<<endl;
		}
		int pi[N];
		for(i=0;i<N;i++)
			pi[N]=1;
		LUP_Solve(lu,pi,B,N-K+1,N);
	}
}