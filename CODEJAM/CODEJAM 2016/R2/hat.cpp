#include<bits/stdc++.h>
#include "boost/algorithm/string.hpp"

using namespace std;

int sum_sub(int* arr,int N)
{
	int sum=0;
	for(int i=0;i<=N;i++)
		sum+=arr[i];
	return sum;
}

int cal_max(int* prio,int N)
{
	int res=1,sum=0;
	int* cal_p=new int[N];
	for(int i=0;i<N;i++)
		cal_p[prio[i]]++;
	for(int i=0;i<N;i++){
		res*=(sum_sub(cal_p,i)-i);
	}
	return res;
}

bool exist(vector<int*>v,int*a,int N )
{
		for(int i=0;i<v.size();i++){
			int count=0;
			for(int j=0;j<N;j++){
				if(v[i][j]==a[j])
					count++;
			}
			if(count==N)
				return true;
		}
		return false;
}

double cal_prob(vector<char*>hat,char* str)
{
	double deno,num=0;
	deno=hat.size();
	string sub(str,strlen(str));
	for(int i=0;i<hat.size();i++){
		string source(hat[i],strlen(hat[i]));
	//	if(contains(source,sub))   //library to check the substring sub is contained within source string or not
	//		num++;
		if(strstr(hat[i],str))
			num++;
	}
	return (num/deno);
}

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("hat.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int N,M;
		fin>>N;
		int* prio=new int[N];
		for(int i=0;i<N;i++)
			fin>>prio[i];
		char* stream=new char[N];
		fin>>stream;
		fin>>M;
		char** substr=new char*[M];
		for(int i=0;i<M;i++)
			substr[i]=new char[N];
		for(int i=0;i<M;i++)
			fin>>substr[i];
		int res=cal_max(prio,N);
		vector<int*> vec;
		while(vec.size()!=res){
			int* a=new int[N];
			for(int i=0;i<N;i++)
				a[i]=-1;
			int p=0;
			for(int j=0;j<N;j++){
		        label: int t=rand()%N;
				for(int i=0;i<p;i++){
					if(a[i]==t)
						goto label;
				}
				if(t>=prio[j]){
					a[p++]=t;
				}
				else
					goto label;
			}
			if(!exist(vec,a,N))
				vec.push_back(a);
		}
		vector<char*>hat;
		for(int i=0;i<res;i++){
			char* s=new char[N];
			for(int j=0;j<N;j++){
				s[j]=stream[vec[i][j]];
			}
			hat.push_back(s);
		}
		vector<double>prob;
		for(int i=0;i<M;i++){
				prob.push_back(cal_prob(hat,substr[i]));
		}
		cout<<"CASE #"<<iter+1<<":";
		for(int i=0;i<M;i++)
			cout<<" "<<prob[i];
		cout<<endl;
	}	
	return 0;
}