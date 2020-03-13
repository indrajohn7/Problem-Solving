#include<bits/stdc++.h>

using namespace std;

int get_sum(map<int, int> work, int i, int j, int arr[])
{
	int sum = 0;
	for(map<int, int>:: iterator it = work.find(arr[i]); it != work.end(); it++){
		sum += it->second;
		if (it == work.find(arr[j]))
			break;
	}

	return sum;
}

int get_optimal_bst(map<int, int> work, int arr[])
{
	int len = work.size();
	int dp[len][len];
	memset(dp, 0, sizeof(dp));
	for(int iter = 0; iter < len ; iter++){
		for(int i = 0; i < len; i++){
			int j = i + iter;
			if (j >= len)
				break;
			if(i == j){
				dp[i][j] = work[arr[i]];
			}
			else{
				int mini = 99999;
				int sum = get_sum(work, i, j, arr);
				for(int k = i; k <= j; k++){
					int cost = 0;
					if (k == i)
						cost = dp[k + 1][j];
					else if (k == j)
						cost = dp[i][j - 1];
					else {
						cost = dp[i][k - 1] + dp[k + 1][j];
					}

					mini = min(cost, mini);
				}
				dp[i][j] = sum + mini;
			}
		}
	}

	return dp[0][len - 1];
}

int main()
{
	int num_test;
	ifstream fin;
	fin.open("optimal.in");
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++){
		int N;
		fin >> N;
		int* arr = new int[N];
		for(int i = 0; i < N; i++)
			fin >> arr[i];
		map<int, int> work;
		for(int i = 0; i < N; i++){
			int freq;
			fin >> freq;
			work[arr[i]] = freq;
		}
		sort(arr, arr + N);
		int res = get_optimal_bst(work, arr);
		cout << "Case #" << iter + 1 << ": " << res << endl;
	}
	return 0;
}
