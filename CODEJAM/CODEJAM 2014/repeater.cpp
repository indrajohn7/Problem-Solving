#include<bits/stdc++.h>
#include<string.h>

using namespace std;
#define MAX 100
int main()
{
	int iter,Num_test;
	ifstream fin;
	fin.open("repeter.in");
	fin>>Num_test;
	for(iter=0;iter<Num_test;iter++){
		int N,i,j,k,alpha_num=0,count=0;
		fin>>N;
		bool lost=false;
		char arr[N][MAX],format[MAX];
		for(i=0;i<N;i++){
			char* str = new char[MAX];
			memset(str,'\0',MAX);
			fin>>str;
			j=0;k=1;
			while(str[j]!='\0' && isalpha(str[j])){
					arr[i][j]=str[j];
					//FORMATTING
					if(i==0){
						if(j==0)
							format[0]=str[j];
						else if(str[j]!=str[j-1]){
							format[k]=str[j];
							k++;
						}
					}
					j++;
			}
			arr[i][j]='\0';
			if(i==0)
				format[k]='\0';
		}
		for(i=0;i<N;i++)
			cout<<arr[i]<<"\t";
		cout<<std::endl;
		for(i=0;i<N;i++){
			j=0;k=0;
			while(arr[i][j]!='\0'){
				if(j==0 && arr[i][j]!=format[k]){
					lost=true;
					break;
				}
				else if(j==0 && arr[i][j]==format[k]){
					j++;
					k++;
				}
				else if(arr[i][j]!=arr[i][j-1]){
					if(arr[i][j]!=format[k]){
						lost=true;
						break;
					}
						k++;
						j++;
				}
				else
					j++;
			}
			if(lost)
				break;
		}
		if(!lost){
			int** count_alpha = new int*[N]; //[strlen(format)];
			for(k=0;k<N;k++)
				count_alpha[k]=new int[strlen(format)];
			for(i=0;i<N;i++){
				for(j=0;j<strlen(format);j++)
					count_alpha[i][j]=0;
			}
		//	for(k=0;k<strlen(format);k++){
				for(i=0;i<N;i++){
					j=0;
					k=0;
					while(arr[i][j]!='\0'){
						if(j==0)
							count_alpha[i][k]++;
						else if(arr[i][j]==arr[i][j-1])
							count_alpha[i][k]++;
						else{
							k++;
							count_alpha[i][k]++;
						}
						j++;
					}
				}
		//	}
		/*
		for(i=0;i<N;i++){
			for(j=0;j<strlen(format);j++)
				cout<<count_alpha[i][j]<<"\t";
			cout<<endl;
		}
		*/
			int count_num[N]; //=new int[strlen(format)];
		//	memset(count_num,0,N);
			count=0;
			for(j=0;j<strlen(format);j++){
				for(i=0;i<N;i++)
					count_num[i]=0;
				
				for(i=0;i<N;i++){
					count_num[count_alpha[i][j]-1]++;
				}
				int max=0,idx=0;
				for(i=0;i<N;i++){
					if(count_num[i]>max){
						max=count_num[i];
						idx=i;
					}
				}
				if(max!=1){
				for(i=0;i<N;i++){
					count+=abs(i-idx)*count_num[i];
				}
				}
				else{
					idx=(N-1)/2;
					for(i=0;i<N;i++){
						count+=abs(i-idx)*count_num[i];
				}					
			}
		}
		cout<<"CASE #"<<iter+1<<":\t"<<count<<endl;
	}
	else
		cout<<"CASE #"<<iter+1<<":\t"<<"FEGLA WON"<<endl;
	}
	return 0;
}