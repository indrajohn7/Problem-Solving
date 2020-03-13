#include<bits/stdc++.h>

using namespace std;
int N;


#define UNASSIGNED 0
 
 
// This function finds an entry in grid that is still unassigned
bool FindUnassignedLocation(int** grid, int &row, int &col);
 
// Checks whether it will be legal to assign num to the given row,col
bool isSafe(int** grid, int row, int col, int num);
 
/* Takes a partially filled-in grid and attempts to assign values to
  all unassigned locations in such a way to meet the requirements
  for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool SolveSudoku(int** grid)
{
    int row, col;
	
	//row=col=0;
    // If there is no unassigned location, we are done
    if (!FindUnassignedLocation(grid, row, col))
       return true; // success!
 
    // consider digits 1 to 9
    for (int num = 1; num <= N; num++)
    {
        // if looks promising
        if (isSafe(grid, row, col, num))
        {
            // make tentative assignment
            grid[row][col] = num;
 
            // return, if success, yay!
            if (SolveSudoku(grid))
                return true;
 
            // failure, unmake & try again
            grid[row][col] = UNASSIGNED;
        }
    }
    return false; // this triggers backtracking
}
 
/* Searches the grid to find an entry that is still unassigned. If
   found, the reference parameters row, col will be set the location
   that is unassigned, and true is returned. If no unassigned entries
   remain, false is returned. */
bool FindUnassignedLocation(int** grid, int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
 
/* Returns a boolean which indicates whether any assigned entry
   in the specified row matches the given number. */
bool UsedInRow(int** grid, int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
/* Returns a boolean which indicates whether any assigned entry
   in the specified column matches the given number. */
bool UsedInCol(int** grid, int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
/* Returns a boolean which indicates whether any assigned entry
   within the specified 3x3 box matches the given number. */
bool UsedInBox(int** grid, int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < sqrt(N); row++)
        for (int col = 0; col < sqrt(N); col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}
 
/* Returns a boolean which indicates whether it will be legal to assign
   num to the given row,col location. */
bool isSafe(int** grid, int row, int col, int num)
{
    /* Check if 'num' is not already placed in current row,
       current column and current 3x3 box */
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row%((int)sqrt(N)) , col - col%((int)sqrt(N)), num);
}
 
/* A utility function to print grid  */
void printGrid(int** grid)
{
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++)
             printf("%2d", grid[row][col]);
        printf("\n");
    }
}

bool UsedInRow1(int** grid, int row,int colu, int num)
{
    for (int col = 0; col < N; col++)
        if (col!=colu && grid[row][col] == num)
            return true;
    return false;
}
 
/* Returns a boolean which indicates whether any assigned entry
   in the specified column matches the given number. */
bool UsedInCol1(int** grid, int rowe,int col, int num)
{
    for (int row = 0; row < N; row++)
        if (row!= rowe && grid[row][col] == num)
            return true;
    return false;
}



void DoSwap(int** arr,int** temp,int row,int col,int direction)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			temp[i][j]=arr[i][j];
	if(direction==0)
		return;
	else if(direction == 1){
		for(int i=row;i<row+(int)(sqrt(N));i++){
			for(int j=col;j<col+(int)(sqrt(N));j++)
				swap(temp[i][j],temp[i-(int)(sqrt(N))][j]);
		}
	}
	
	else if(direction == 2){
		for(int i=row;i<row+(int)(sqrt(N));i++){
			for(int j=col;j<col+(int)(sqrt(N));j++)
				swap(temp[i][j],temp[i+(int)(sqrt(N))][j]);
		}
	}
	
	else if(direction == 3){
		for(int i=row;i<row+(int)(sqrt(N));i++){
			for(int j=col;j<col+(int)(sqrt(N));j++)
				swap(temp[i][j],temp[i][j-(int)(sqrt(N))]);
		}
	}
	
	else if(direction == 4){
		for(int i=row;i<row+(int)(sqrt(N));i++){
			for(int j=col;j<col+(int)(sqrt(N));j++)
				swap(temp[i][j],temp[i][j+(int)(sqrt(N))]);
		}
	}
}


bool IsSwapping(int** arr)
{
	//int** temp=arr;
	int** temp=new int*[N];
	for(int p=0;p<N;p++)
		temp[p]=new int[N];
	for(int r=0;r<sqrt(N);r++){
		for(int c=0;c<sqrt(N);c++){
			int row,col;
			
			row=r*sqrt(N);
			col=c*sqrt(N);
			int up,down,left,right;
			up=1;
			down=2;
			left=3;
			right=4;
			if(row == 0 ){
				up=0;
			}if(col==0)
				left=0;
			if((row+(int)sqrt(N)) >= N)
				down=0;
			if((col+(int)sqrt(N)) >= N)
				right=0;
			DoSwap(arr,temp,row,col,up);
			for(int i=row;i<row+(int)(sqrt(N));i++){
				for(int j=col;j<col+(int)(sqrt(N));j++){
				
					int num=temp[i][j];					
					if(UsedInRow1(temp, i,j, num) ||
						UsedInCol1(temp, i,j, num))
						return false;
				}
			}
			DoSwap(arr,temp,row,col,down);
			for(int i=row;i<row+(int)(sqrt(N));i++){
				for(int j=col;j<col+(int)(sqrt(N));j++){
				
					int num=temp[i][j];					
					if(UsedInRow1(temp, i,j, num) ||
						UsedInCol1(temp,i, j, num))
						return false;
				}
			}
			
			DoSwap(arr,temp,row,col,left);
			for(int i=row;i<row+(int)(sqrt(N));i++){
				for(int j=col;j<col+(int)(sqrt(N));j++){
				
					int num=temp[i][j];					
					if(UsedInRow1(temp, i,j, num) ||
						UsedInCol1(temp,i, j, num))
						return false;
				}
			}
			
			DoSwap(arr,temp,row,col,right);
			for(int i=row;i<row+(int)(sqrt(N));i++){
				for(int j=col;j<col+(int)(sqrt(N));j++){
				
					int num=temp[i][j];					
					if(UsedInRow1(temp, i,j, num) ||
						UsedInCol1(temp,i, j, num))
						return false;
				}
			}
		}
	}
	
	return true;
}


int SolveMagicSquare(vector < vector < int > > input1)
{
	//Write code here
	N=input1.size();
	int** arr=new int*[N];
	for(int i=0;i<N;i++)
		arr[i]=new int[N];
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==0 && j==0 && input1[i][j]>1)
				return 0;
			arr[i][j]=input1[i][j];
		}
	}
	arr[0][0]=1;
	if (SolveSudoku(arr) == true && IsSwapping(arr) == true){
		printGrid(arr);
		return 1;
	}
	else
		return 0;
	
}


int main()
{
	ifstream fin;
	fin.open("sudo.in");
	int row,col;
	fin>>row>>col;
	vector< vector < int > > vec;
	for(int i=0;i<row;i++){
		vector<int> v;
		for(int j=0;j<col;j++){
			int t;
			fin>>t;
			v.push_back(t);
		}
		vec.push_back(v);
		v.clear();
	}
	int output = SolveMagicSquare(vec);
    cout << output << endl;
    return 0;
}


/*
int main() {
    int output;
    int ip1_rows = 0;
    int ip1_cols = 0;
    cin >> ip1_rows >> ip1_cols;
    vector< vector < int > > ip1(ip1_rows);
    for(int ip1_i=0; ip1_i<ip1_rows; ip1_i++) {
        for(int ip1_j=0; ip1_j<ip1_cols; ip1_j++) {
            int ip1_tmp;
            cin >> ip1_tmp;
            ip1[ip1_i].push_back(ip1_tmp);
        }
    }
    output = SolveMagicSquare(ip1);
    cout << output << endl;
    return 0;
}
*/
