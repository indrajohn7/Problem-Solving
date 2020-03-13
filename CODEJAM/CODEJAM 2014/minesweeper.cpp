#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Num_Test,iter;
	ifstream fin;
	fin.open("mine.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int r,c,m;
		bool impossible=false,swap_val=false;;
		fin>>r;
		fin>>c;
		fin>>m;
		if(r>c){
			swap(r,c);
			swap_val=true;
		}
		char ret[r][c],ret_final[r][c];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				ret[i][j]='.';
		}
		if (m == 0) 
            ret[0][0] = 'c';
		else if(m == r * c - 1){
			for (int i = 0; i < r; i++)
                 for (int j = 0; j < c; j++) ret[i][j] = '*';
           ret[0][0] = 'c';
		}
		else if (r == 1) {
            for (int j = 0; j < m; j++) ret[0][j] = '*';
                ret[0][c - 1] = 'c';
		}
		else if (m >= r * c - 3)
			impossible=true;
		
		else if (r == 2) {
               if (m % 2 == 1) {
                    impossible=true;
               }
			   if(!impossible){
             for (int i = 0; i < 2; i++)
                 for (int j = 0; j < m / 2; j++) ret[i][j] = '*';
                  ret[0][c - 1] = 'c';
			   }
		   }
		 if(!(ret[0][0]=='c' || ret[0][c-1]=='c' || impossible==true)){
			 for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) ret[i][j] = '*';
  m = r * c - m;
  if (m == 5 || m == 7) {
    impossible=true;
  }
  else if (m == 2 * r + 1) {
    for (int i = 0; i < r - 1; i++)
      for (int j = 0; j < m / r; j++) ret[i][j] = '.';
    ret[0][m / r] = '.';
    ret[1][m / r] = '.';
    ret[2][m / r] = '.';
    ret[0][0] = 'c';
  }
  else if (m >= 2 * r) {
    for (int i = 0; i < r; i++)
      for (int j = 0; j < m / r; j++) ret[i][j] = '.';
    for (int i = 0; i < m % r; i++) ret[i][m / r] = '.';
    if (m % r == 1) {
      ret[1][m / r] = '.';
      ret[r - 1][m / r - 1] = '*';
    }
    ret[0][0] = 'c';
  }
  else if (m % 2 == 0) {
    for (int i = 0; i < m / 2; i++)
      for (int j = 0; j < 2; j++) ret[i][j] = '.';
    ret[0][0] = 'c';
  }
  for (int i = 0; i < (m - 3) / 2; i++)
    for (int j = 0; j < 2; j++) ret[i][j] = '.';
  ret[0][2] = '.';
  ret[1][2] = '.';
  ret[2][2] = '.';
  ret[0][0] = 'c';
		 }
		 if(swap_val==true && !impossible){
			 for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) 
						ret_final[j][i]=ret[i][j];
		     }
		 }
		 else if(swap_val==false && !impossible){
			 for (int i = 0; i < r; i++) {
                    for (int j = 0; j < c; j++) 
						ret_final[i][j]=ret[i][j];
		     }
		 }
		 
		 cout<<"CASE #"<<iter+1<<":\t"<<endl;
		 if(impossible)
			  cout<<"impossible\n";
		  else{
			  if(swap_val)
				  swap(r,c);
			  for(int i=0;i<r;i++){
				  for(int j=0;j<c;j++)
					  cout<<ret_final[i][j]<<"\t";
				  cout<<endl;
			  }
		  }
			  
	}
    return 0;
}