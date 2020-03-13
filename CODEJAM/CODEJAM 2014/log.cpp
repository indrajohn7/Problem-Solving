#include<bits/stdc++.h>

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
	fin.open("log.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int P,i,j,k,sum=0,num_2=1,flag=2;
		fin>>P;
		int E[P],F[P];
		for(i=0;i<P;i++)
			fin>>E[i];
		for(i=0;i<P;i++){
			fin>>F[P];
			sum+=F[P];
		}
		int* B=new int[temp-1];
		for(i=0;i<P;i++){
			if(E[i]==0)
				F[i]--;
			for(j=0;j<F[i];j++){				
				    B[i*P+j]=E[i];
			}
		}
		temp=sum;
		while(flag!=sum){
			flag*=2;
			num_2++;
		}
		int** A=new int*[temp-1];
		for(i=0;i<temp-1;i++)
			A[i]=new int[num_2];
		for(i=1;i<=num_2;i++){
			vector<int[]> ve(combination(num_2,i));
			for(int k=0;k<combination(num_2,i);k++){
				ve[k]=0;
			}
			for(j=1;j<combination(num_2,i);j++){
				//Here I need to populate the Co-efficient array A. Then LUP decompose and it will be done.
				
			}
		}
		
		
		LU* lu=new LU(temp-1,num_2);
		lu=LU_Decompose(A,temp-1,num_2);
		cout<<"LOWER TRIANGULAR MATRIX:\n";
		for(i=1;i<=temp-1;i++){
			for(j=1;j<=num_2;j++)
				cout<<lu->lower[i][j]<<"\t";
			cout<<endl<<endl;
		}
		cout<<"UPPER TRIANGULAR MATRIX:\n";
		for(i=1;i<=temp-1;i++){
			for(j=1;j<=num_2;j++)
				cout<<lu->upper[i][j]<<"\t";
			cout<<endl<<endl;
		}
		int pi[N];
		for(i=0;i<temp-1;i++)
			pi[i]=1;
		LUP_Solve(lu,pi,B,temp-1,num_2);
	}
}