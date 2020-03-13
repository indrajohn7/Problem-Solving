#include<bits/stdc++.h>
#define N 4

using namespace std;


int main()
{
	int Num_Test,iter;
	ifstream fin;
	fin.open("magic.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int match,match_count=0,i,j,first_row,second_row,arr_frst[N][N],arr_scnd[N][N];
		fin>>first_row;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				fin>>arr_frst[i][j];
			}
		}
	    fin>>second_row;
	    for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				fin>>arr_scnd[i][j];
			}
		} 
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(arr_frst[first_row-1][i]==arr_scnd[second_row-1][j]){
					match=arr_frst[first_row-1][i];
					match_count++;
				}
			}
		}
		cout<<"CASE #"<<iter+1<<":\t";
		if(match_count==1)
			cout<<match<<std::endl;
		else if(match_count==0)
			cout<<"Volunteer cheated!"<<std::endl;
		else if(match_count>1)
			cout<<"Bad magician!"<<std::endl;
	}
	return 0;
}