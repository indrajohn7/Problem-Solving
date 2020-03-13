#include<bits/stdc++.h>

using namespace std;

int mini(int r, int c,int** arr){
	int a[4],i;
	a[0]=arr[r-1][c];
	a[1]=arr[r+1][c];
	a[2]=arr[r][c-1];
	a[3]=arr[r][c+1];
	int min=a[0];
	for(i=1;i<4;i++){
		if(a[i]<min)
			min=a[i];
	}
	return min;
}

int mini2(int r, int c, int** arr,int R, int C)
{
	int a[4],i;
	a[0]=arr[r-1][c];
	a[1]=arr[r+1][c];
	a[2]=arr[r][c-1];
	a[3]=arr[r][c+1];
	if(R==r-1)
		a[0]=-1;
	else if(R==r+1)
		a[1]=-1;
	else if(C==c-1)
		a[2]=-1;
	else if(C==c+1)
		a[3]=-1;
	/*
	for(i=0;i<4;i++){
		if(a[i]==arr[R][C] && )
			a[i]=-1;
	}*/		
	int min=999999999;
	for(i=0;i<4;i++){
		if(a[i]>0 && a[i]<min)
			min=a[i];
	}
	return min;
}

int GetWaterLevel(int input1,int input2,int input3[])
{
	//Write code here
	int i,j,k=0;
	int** grid=new int*[input1];
	for(i=0;i<input1;i++)
	    grid[i]=new int[input2];
	for(i=0;i<input1;i++){
		for(j=0;j<input2;j++)
			grid[i][j]=input3[k++];
	}
	int count=0,volume=0;
	while(count!=2){
		for(i=1;i<input1-1;i++){
			for(j=1;j<input2-1;j++){
				if(grid[i][j]<mini(i,j,grid)){
					int l=mini(i,j,grid);					
					volume+=l-grid[i][j];
					grid[i][j]=l;
				}
				else if(grid[i][j]==mini(i,j,grid)){
					if(grid[i][j]==grid[i-1][j] && i-1==0)
						continue;
					else if(grid[i][j]==grid[i+1][j] && i+1==input1-1)
						continue;
					else if(grid[i][j]==grid[i][j-1] && j-1==0)
						continue;
					else if(grid[i][j]==grid[i][j+1] && j+1==input2-1)
						continue;
					else{
						if(grid[i][j]==grid[i-1][j]){
							int l1,l2,val;
							l1=mini2(i,j,grid,i-1,j);
							l2=mini2(i-1,j,grid,i,j);
							val=min(l1,l2);
							volume+=2*(val-grid[i][j]);
							grid[i][j]=grid[i-1][j]=val;
						}
							
				    	else if(grid[i][j]==grid[i+1][j]){
							int l1,l2,val;
							l1=mini2(i,j,grid,i+1,j);
							l2=mini2(i+1,j,grid,i,j);
							val=min(l1,l2);
							volume+=2*(val-grid[i][j]);
							grid[i][j]=grid[i+1][j]=val;
						}
						else if(grid[i][j]==grid[i][j-1]){
							int l1,l2,val;
							l1=mini2(i,j,grid,i,j-1);
							l2=mini2(i,j-1,grid,i,j);
							val=min(l1,l2);
							volume+=2*(val-grid[i][j]);
							grid[i][j]=grid[i][j-1]=val;
						}
						else if(grid[i][j]==grid[i][j+1]){
							int l1,l2,val;
							l1=mini2(i,j,grid,i,j+1);
							l2=mini2(i,j+1,grid,i,j);
							val=min(l1,l2);
							volume+=2*(val-grid[i][j]);
							grid[i][j]=grid[i][j+1]=val;
						}
					}
				}
			}
		}
		count++;
	}
	return volume;
}

int main()
{
	ifstream fin;
	fin.open("water.in");
	int iter, Num_Test;
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int R,C;
		fin>>R>>C;
		int* a=new int[R*C];
		for(int i=0;i<R*C;i++)
			fin>>a[i];
		int val=GetWaterLevel(R,C,a);
		cout<<"Case #"<<iter+1<<": "<<val<<endl;
	}
}