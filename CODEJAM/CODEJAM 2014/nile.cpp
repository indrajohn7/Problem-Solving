#include<bits/stdc++.h>

using namespace std;

bool left_move(int** stream,int r,int c,int R,int C){
	if(c==0)
		return false;
	else if(stream[r][c-1]!=0)
		return false;
	else 
		return true;
		
}

bool up_move(int** stream,int r,int c,int R,int C){
	if(r==0)
		return false;
	else if(stream[r-1][c]!=0)
		return false;
	else
		return true;
	
}

bool right_move(int** stream,int r,int c,int R,int C){
	if(c==C-1)
		return false;
	else if(stream[r][c+1]!=0)
		return false;
	else 
		return true;
}

int main()
{
	int iter,Num_Test;
	ifstream fin;
	fin.open("nile.in");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int W,H,B,X0,Y0,X1,Y1,i,j,k,flow=0,count;
		fin>>W>>H>>B;
		int** building = new int*[B];
		for(i=0;i<B;i++)
			building[i]=new int[4];
		for(i=0;i<B;i++){
			for(j=0;j<4;j++){
				fin>>building[i][j];
			}
		}
		int** stream = new int*[H];
		for(i=0;i<H;i++)
			stream[i]=new int[W];
		for(i=0;i<H;i++){
			for(j=0;j<W;j++)
				stream[i][j]=0;
		}
        for(i=0;i<B;i++){
			X0=building[i][0];
			Y0=building[i][1];
			X1=building[i][2];
			Y1=building[i][3];
			for(j=H-1-Y0;j>=H-1-Y1;j--){
				for(k=X0;k<=X1;k++){
					stream[j][k]=-1;
				}
			}
		}/*
		for(i=0;i<H;i++){
			for(j=0;j<W;j++)
				cout<<stream[i][j]<<"\t";
			cout<<endl;
		}
		*/
		for(i=0;i<W;i++){
			j=H-1;
			k=i;
			if(stream[H-1][i]==-1)
					continue;
			while(j>=0 && k<W && k>=0){				
					stream[j][k]=1;
					if(j==0)
						break;
				    else if(left_move(stream,j,k,H,W)==true){
						k--;
					}
					else if(up_move(stream,j,k,H,W)==true){
						j--;
					}
					else if(right_move(stream,j,k,H,W)==true){
						k++;
					}
					
					else
						break;
			}
		}/*
		for(i=0;i<H;i++){
			for(j=0;j<W;j++)
				cout<<stream[i][j]<<"\t";
			cout<<endl;
		}*/
		for(i=0;i<W;i++){
			if(stream[0][i]==1)
				flow++;
		}
		/*
        for(i=0;i<W;i++){
			count=0;
			for(j=H-1;j>=0;j--){
				if(stream[j][i]==1)
					break;
				else
					count++;
			}
			if(count==H)
				flow++;
		}
		*/
        cout<<"CASE #"<<iter+1<<":\t"<<flow<<endl;		
	}
	return 0;
}