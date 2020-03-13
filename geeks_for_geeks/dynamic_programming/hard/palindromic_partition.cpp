#include<bits/stdc++.h>

using namespace std;


bool is_palin(char* str, int start, int len)
{
	bool ret = true;
	int end = start + len - 1; 
	for(int i = 0; i < (len / 2); i++){
		if(str[start + i] != str[end - i])
			return false;
	}

	return true;
}

int get_partition(char* arr)
{
	int len = strlen(arr);
	int dp[len][len];
	for(int i = 0; i < len; i++)
		for(int j = 0; j < len; j++)
			dp[i][j] = 0;

	for(int l = 1; l <= len; l++){
		for(int k = 0; k <= (len - l); k++){
			if(is_palin(arr, k, l))
				dp[k][k + l - 1] = 0;
			else {
				//dp[k][k + l - 1] = 1 + min (dp[k][k + l - 2], dp[k + 1][k + l - 1]);
				
				int min_cost = 1 + min (dp[k][k + l - 2], dp[k + 1][k + l - 1]);
				for(int p = k; p < (k + l - 1); p++){
					int temp = 1 + dp[k][p] + dp[p + 1][k + l - 1];
					if (temp < min_cost)
						min_cost = temp;
				}
				dp[k][k + l - 1] = min_cost;
					
			}
		}
	}
	
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len; j++)
			cout << dp[i][j] << "\t";
		cout << endl;
	}

	return dp[0][len - 1];
}

int main()
{
	int num_test;
	ifstream fin;
	fin.open("partition.in");
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++){
		char arr[100];
		memset(arr, '\0', 100);
		fin >> arr;
		int res = get_partition(arr);
		cout << "Case #" << iter + 1 << ": " << res << endl;
	}
	return 0;
}
