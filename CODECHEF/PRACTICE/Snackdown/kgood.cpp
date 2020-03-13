#include<bits/stdc++.h>

using namespace std;
#define NUM 26
#define SIZE 100000
int main()
{
	int Num_Test,iter;
	freopen("kgood.in","r",stdin);
	cin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int arr[NUM]={0};
		char* str=new char[SIZE];
		int N,del=0;
		cin>>str>>N;
		for(int i=0;i<strlen(str);i++){
			arr[tolower(str[i])-'a']++;
		}
		for(int i=0;i<NUM-1; i++){
			if(arr[i]!=0){
				for(int j=i+1;j<NUM;j++){
					if(arr[j]!=0){
						if(abs(arr[i]-arr[j])>N){
							del+=abs(arr[i]-arr[j])-N;
							(arr[i]>arr[j])?(arr[i]-=(abs(arr[i]-arr[j])-N)):(arr[j]-=(abs(arr[i]-arr[j])-N));
							//del+=abs(arr[i]-arr[j])-N;
						}
					}
				}
			}
		}
		cout<<del<<endl;
	}
	return 0;
}