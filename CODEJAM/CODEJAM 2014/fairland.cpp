#include<bits/stdc++.h>

using namespace std;

typedef struct Employee{
	int salary;
	int under;
	int emp_list[100];
	int status;
}employee;

#define MAX 1000

void sort(int a[MAX],int n)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}


int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("fairland.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int min,max,S0,Cs,As,Rs,M0,Cm,Am,Rm,N,D,i,j,k,l;
		fin>>N>>D;
		int level[N];
		for(i=0;i<N;i++)
			level[i]=0;
		vector<employee> emp(N);
	    int S[N],M[N];
		fin>>S0>>As>>Cs>>Rs;
		fin>>M0>>Am>>Cm>>Rm;
		S[0]=S0;
		M[0]=M0;
		min=S[0]-D;
		max=S[0]+D;
		for(i=1;i<N;i++){
			S[i]=(S[i-1]*As+Cs)%Rs;
			M[i]=(M[i-1]*Am+Cm)%Rm;
		}
		for(int i=1;i<N;i++)
			M[i]%=i;
		//initialise
		for(i=0;i<N;i++){
			emp[i].status=true;
			emp[i].under=0;
			for(j=0;j<100;j++){
				emp[i].emp_list[j]=-1;
			}
		}
		emp[0].salary=S[0];
		for(i=1;i<N;i++){
			emp[i].salary=S[i];
			emp[M[i]].emp_list[level[M[i]]++]=i;       //I can use under also.. 
			emp[M[i]].under++;
		//	if(min>S[i])
		//		min=S[i];
		}
		int count=0;
		for(i=1;i<N;i++){
			if(emp[i].salary<min || emp[i].salary>max){
				emp[i].status=false;
				for(j=0;j<emp[i].under;j++){
					emp[emp[i].emp_list[j]].status=false;					
				}
			}
			else 
			{
				if(emp[M[i]].salary<min || emp[M[i]].salary>max){
					emp[i].status=false;
					emp[M[i]].status=false;
					for(j=0;j<emp[i].under;j++){
						emp[emp[i].emp_list[j]].status=false;
					}
					for(j=0;j<emp[M[i]].under;j++){
						emp[emp[M[i]].emp_list[j]].status=false;
					}
				}
			}
		}
		for(i=0;i<N;i++){
			if(emp[i].status==false)
				count++;
		}
		int balance[Rs];
		for(i=0;i<Rs;i++)
			balance[i]=0;
		int flag=0,m,t;
		l=0;
		for(i=0;i<N;i++){
			if(emp[i].salary>=min && emp[i].salary<=S0){
				for(j=0;j<l;j++){
					if(balance[j]==emp[i].salary)
						flag=1;
				}
				if(flag==0 && emp[i].status==true)
					balance[l++]=emp[i].salary;
			}
			flag=0;
		}
		k=l;
		l=0;
		//Second scanning
		int sal[Rs];
		for(i=0;i<Rs;i++)
			sal[i]=0;
		int rej[N];
		for(i=0;i<N;i++)
			rej[i]=-1;
		sort(balance,k);
		t=k;
		k=1;
		min=balance[0];
		while(min<=S0 && t!=0){
			m=0;
			for(i=1;i<N;i++){
				if((emp[i].salary>(min+D) || emp[i].salary<(min)) && emp[i].status==true){
				    sal[l]++;
					rej[m++]=i;
					emp[i].status=false;
					for(j=0;j<emp[i].under;j++){
						rej[m++]=emp[i].emp_list[j];
						emp[emp[i].emp_list[j]].status=false;
					}
					sal[l]+=emp[i].under;
					}
					else if(emp[i].status==false)
						continue;
					else if(emp[i].salary>=(min) && emp[i].salary<=(min+D)){
						if(emp[M[i]].salary<(min) || emp[M[i]].salary>(min+D) || emp[M[i]].status==false){
							emp[i].status=false;
							emp[M[i]].status=false;
							rej[m++]=i;
							sal[l]++;
							sal[l]+=emp[i].under;
							for(j=0;j<emp[i].under;j++){
								emp[emp[i].emp_list[j]].status=false;
								rej[m++]=emp[i].emp_list[j];
							}
							for(j=0;j<emp[M[i]].under;j++){
								emp[emp[M[i]].emp_list[j]].status=false;
								rej[m++]=emp[i].emp_list[j];
							}
						}
					}
				}
				for(j=0;j<m;j++)
					emp[rej[j]].status=true;
				l++;
				min=balance[k++];
				t--;
			}
		sort(sal,l);
		cout<<"CASE #"<<iter+1<<":\t"<<N-sal[0]-count<<endl;
		
	}
	return 0;
}
	