#include<bits/stdc++.h>

using namespace std;

#define MACHINE 2


bool get_votes(int* arr, int N, int time, int machine)
{
	int dp[N + 1][time + 1];
	int sum = 0;

	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < N; i++)
		sum += arr[i];
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= time; j++){
			if (arr[i - 1] <= j)
				dp[i][j] = max(dp[i - 1][j], (arr[i - 1] + dp[i - 1][j - arr[i]]));
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return ((sum - dp[N][time]) <= time);
}

int main()
{
	int num_test;
	ifstream fin;
	fin.open("voters.in");
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++){
		int people, max_time, num;
		fin >> people >> max_time;
		num = MACHINE;
		int* arr = new int[people];
		for(int i = 0; i < people; i++)
			fin >> arr[i];
		bool res = get_votes(arr, people, max_time, num);
		cout << "Case #" << iter + 1 << ": ";
		if (res)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}
