#include<bits/stdc++.h>

using namespace std;

char* longestIncreasingSubsequence(char* input1)
{
	int *lis, i, j, max = 0;
	int n=strlen(input1);
    lis = (int*) malloc ( sizeof( int ) * n );
	
    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++ )
        lis[i] = 1;
	
	vector<char> vec;
	char t;
    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ ) 
            if ( input1[i] >= input1[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
				vec.push_back(input1[j]);
				t=input1[i];			
			}
	vec.push_back(t);
 
    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
 
    /* Free memory to avoid memory leak */
    free(lis);
	
	char* res=new char[n];
	for(int i=0;i<n;i++){
		res[i]=vec[i];
	}
	
    return res;
}


int main()
{
	char* output;
    char* ip1;
    ip1 = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",ip1);
    output = longestIncreasingSubsequence(ip1);
    printf("%s\n", output);
    return 0;
}