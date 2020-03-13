// C++ program to find number of ways to get sum 'x' with 'n'
// dice where every dice has 'm' faces

#include<bits/stdc++.h>
using namespace std;
 
// The main function that returns number of ways to get sum 'x'
// with 'n' dice and 'm' with m faces.
int findWays(int m, int n, int x)
{
    // Create a table to store results of subproblems.  One extra 
    // row and column are used for simpilicity (Number of dice
    // is directly used as row index and sum is directly used
    // as column index).  The entries in 0th row and 0th column
    // are never used.
    int table[n + 1][x + 1];
    memset(table, 0, sizeof(table)); // Initialize all entries as 0
 
    // Table entries for only one dice
    for (int j = 1; j <= m && j <= x; j++)
        table[1][j] = 1;
 
    // Fill rest of the entries in table using recursive relation
    // i: number of dice, j: sum
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= x; j++)
            for (int k = 1; k <= m && k < j; k++)
                table[i][j] += table[i-1][j-k];
 
    /* Uncomment these lines to see content of table
    for (int i = 0; i <= n; i++)
    {
      for (int j = 0; j <= x; j++)
        cout << table[i][j] << " ";
      cout << endl;
    } */
    return table[n][x];
}
 
// Driver program to test above functions
int main()
{
    int Num_Test,iter;
	ifstream fin;
	ofstream fout;
	fout.open("zombies.txt");
	fin.open("fighting_the_zombie.txt");
	fin>>Num_Test;
	for(iter=0;iter<Num_Test;iter++){
		int val,spell;
		fin>>val>>spell;
		int** arr=new int*[spell];
		for(int i=0;i<spell;i++){
			arr[i]=new int[3];
			for(int j=0;j<3;j++)
				arr[i][j]=0;
		}
		for(int i=0;i<spell;i++){
			int k=0;
			char* str=new char[100];
			memset(str,'\0',100);
			fin>>str;
			int x,y,s;
			char c;
			s=0;
			if(strchr(str,'-') || strchr(str,'+')){
				if(strchr(str,'-')){
					sscanf(str,"%d%c%d-%d",&x,&c,&y,&s);
					s=s*(-1);
				}else if(strchr(str,'+')){
					sscanf(str,"%d%c%d+%d",&x,&c,&y,&s);
				}
			}else{
				sscanf(str,"%d%c%d",&x,&c,&y);
			}
			arr[i][k++]=x;
			arr[i][k++]=y;
			arr[i][k++]=s;
		}
		unsigned long int MAX,max=-1; 
		MAX=max;
		int idx=-1;
		bool flag=false;
		bool high=false;
		vector<int> vec;
		for(int i=0;i<spell;i++){
			
			if(((arr[i][0]*arr[i][1])+arr[i][2])>=val){
				unsigned long int iter=pow(arr[i][1],arr[i][0]);
			//	vec.push_back(i);
				if(iter<max){
					
					if(idx==-1){
						max=iter;
						idx=i;
						flag=true;
					}else if((arr[idx][0]+arr[idx][2])<val){
						max=iter;
						idx=i;
						flag=true;
					}else if((arr[i][0]+arr[i][2])>=val){
						max=iter;
						idx=i;
						flag=true;
					}
				}else if(iter==max){
					if(arr[idx][2]<arr[i][2]){
						idx=i;
						flag=true;
					}
				}
			}
		}
		float prob;
		if(flag){
			int min=val-arr[idx][2];
			unsigned long int res=0;
			for(int i=0;i<=(min-1);i++){
				res+=findWays(arr[idx][1],arr[idx][0],i);
			}
				unsigned long int iteration=(unsigned long int)pow(arr[idx][1],arr[idx][0]);
				prob=(float)((iteration-res)/iteration);
				//cout<<prob<<endl;
		}else{
			prob=0;
		}
		fout<<"Case #"<<iter+1<<": "<<prob<<endl;
	}
    return 0;
}