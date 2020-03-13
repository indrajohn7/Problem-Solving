#include<bits/stdc++.h>

using namespace std;

float sum(float arr[],int N)
{
	float s=0;
	for(int i=0;i<N;i++)
		s+=arr[i];
	return s;
}

bool percent(float arr[],int N)
{
	for(int i=0;i<N;i++){
		float t;
		t=(float)(arr[i]/sum(arr,N));
		if((t*100)>50)
			return false;
	}
	return true;
}

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("senate.in");
	fin>>Num_Test;
	ofstream fout;
	fout.open("out.txt");
	for(iter=0;iter<Num_Test;iter++){
		int N,i,j,k;
		char str[26];
		for(i=0;i<26;i++)
			str[i]='A'+i;
		fin>>N;
		float arr[N];
		for(i=0;i<N;i++)
			fin>>arr[i];
		//i=max(arr);
		vector<char*> v;
		while(sum(arr,N)!=0){
			int t=rand()%N;
			if(arr[t]>0)
				arr[t]--;
			else
				continue;
			if(percent(arr,N)){
				char* s=new char[2];
				s[0]=str[t];
				s[1]='\0';
				v.push_back(s);
				continue;
			}
			else{
				arr[t]++;
				t=rand()%N;
				int t2=rand()%N;
				if(arr[t]>0 && arr[t2]>0){
					arr[t]--;
					arr[t2]--;
				}
				else
					continue;
				if(percent(arr,N)){
					char* s=new char[3];
					s[0]=str[t];
					s[1]=str[t2];
					s[2]='\0';
					v.push_back(s);
				}
				else{
					arr[t]++;
					arr[t2]++;
				}
			}
		}
		fout<<"Case #"<<iter+1<<":";
		for(i=0;i<v.size();i++){
			fout<<" "<<v[i];			
		}
		fout<<endl;
	}
	return 0;
}