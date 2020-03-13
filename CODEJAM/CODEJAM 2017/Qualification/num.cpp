#include<bits/stdc++.h>

using namespace std;
#define SIZE 20
int main()
{
	int iter,Num_test;
	ifstream fin;
	ofstream fout;
	fout.open("num.txt");
	fin.open("num.in");
	fin>>Num_test;
	for(iter=0;iter<Num_test;iter++){
		int arr[SIZE],N,len=0;
		char* buff=new char[SIZE];
		memset(buff,'\0',SIZE);
		fin>>buff;
		len=strlen(buff);
		bool done=false;
		for(int i=0;i<len;i++)
			arr[i]=buff[i]-'0';
		while(!done){
			for(int i=len-1 ;i>=1;i--){
				if(arr[i-1]>arr[i]){
					for(int j=i;j<len;j++)
						arr[j]=9;
					if(arr[i-1]!=0)
						arr[i-1]=arr[i-1]-1;
					else
						arr[i-1]=9;
				}
			}
			done=true;
			for(int i=0;i<len-1;i++){
				if(arr[i]>arr[i+1]){
					done =false;
					break;
				}
			}
		}
		
		fout<<"Case #"<<iter+1<<": ";
		for(int i=0;i<len;i++){
			if(arr[i]!=0){
				fout<<arr[i];
			}
		}
		fout<<endl;
	}
	return 0;
}