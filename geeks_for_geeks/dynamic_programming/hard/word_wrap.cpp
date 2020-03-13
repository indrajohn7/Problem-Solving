#include<bits/stdc++.h>

using namespace std;

#define INF 999999

int get_min_wrap_cost(char** arr, int N, int width)
{
	int dp[N][N];
	//memset(dp, INF, sizeof(dp));
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			dp[i][j] = INF;


	for(int i = 0; i < N; i++){
		for(int j = i; j < N; j++){
			int len = 0;
			for(int k = i; k <= j; k++){
				len += strlen(arr[k]);
				if (k != j)
					len += 1;
				if (len > width)
					break;
			}
			if(len <= width){
				dp[i][j] = (int)pow((width - len), 2);
			} else {
				break;
			}
		}
	}

	int cost[N], partition[N];
	for(int i = N - 1; i >= 0; i--){
		int min_cost = INF, min_idx = N;
		for(int j = N - 1; j >= i; j--){
			if (j == N - 1 && dp[i][j] != INF){
				min_cost = dp[i][j];
				min_idx = j;
			} else if(dp[i][j] != INF){
				int temp_cost;
				temp_cost = dp[i][j] + cost[j + 1];
				if(min_cost > temp_cost){
					min_cost = temp_cost;
					min_idx = j;
				}
			}
		}
		cost[i] = min_cost;
		partition[i] = min_idx;
	}

	cout << "Distributions:\n";
	int last = 0;
	for(int i = 0; i < N; i++){
		bool flag = false;
		for(int j = i; j <= partition[i]; j++){
			if (j > last || j == 0){
				last = j;
				cout << arr[j] << " ";
				flag = true;
			} else 
				break;
		}
		if (flag)
			cout << endl;
	}
	return cost[0];
}


int main()
{
	int num_test;
	ifstream fin;
	fin.open("wrapper.in");
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++){
		int N, width;
		fin >> N >> width;
		char** arr = new char*[N];
		for(int i = 0; i < N; i++){
			arr[i] = new char[width + 1];
			memset(arr[i], '\0', width + 1);
			fin >> arr[i];
		}

		int res = get_min_wrap_cost(arr, N, width);
		cout << "Case #" << iter + 1 << ": " << res << endl;
	}

	return 0;
}
