#include<bits/stdc++.h>

using namespace std;


char* get_max_repeat(char* str)
{
	int len = strlen(str);
	int dp[len+1][len+1];
	for(int i = 0; i <= len; i++)
		for(int j = 0; j <= len; j++)
			dp[i][j] = 0;

	char* res = NULL;
	int max = -1, pos = -1;
	for(int i = 1; i <= len; i++) {
		for(int j = len ; j >= 1; j--){
			if(str[i-1] == str[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			if ((((i + dp[i][j] - 1) < j) || ((j + dp[i][j] - 1) < i)) && (dp[i][j] > max)){
				max = dp[i][j];
				pos = i;
			}
		}
	}

	if(max == -1){
		return res;
	} else {
		cout << "Len :" << max << endl;
		res = new char[max+1];
		strncpy(res, &str[pos - max], max);
		res[max] = '\0';
	}

	return res;
}

int main()
{
	int num_test;
	ifstream fin;
	fin.open("overlap.in");
	fin >> num_test;
	for (int iter = 0; iter < num_test; iter++){
		char str[100];
		memset(str, '\0', sizeof(str));
		fin >> str;
		char* res = get_max_repeat(str);
		if(res)
			cout<< "Case #" << iter+1 << ": " << res << endl;
	}

	return 0;
}
