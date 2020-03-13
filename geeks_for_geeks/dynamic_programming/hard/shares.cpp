/*
In share trading, a buyer buys shares and sells on future date. Given stock price of n days, the trader is allowed to make at most k transactions, where new transaction can only start after previous transaction is complete, find out maximum profit that a share trader could have made.

Input:  
Price = [10, 22, 5, 75, 65, 80]
    K = 2
Output:  87
Trader earns 87 as sum of 12 and 75
Buy at price 10, sell at 22, buy at 
5 and sell at 80

Input:  
Price = [12, 14, 17, 10, 14, 13, 12, 15]
    K = 3
Output:  12
Trader earns 12 as sum of 5, 4 and 3
Buy at price 12, sell at 17, buy at 10 
and sell at 14 and buy at 12 and sell
at 15
 
Input:  
Price = [100, 30, 15, 10, 8, 25, 80]
    K = 3
Output:  72
Only one transaction. Buy at price 8 
and sell at 80.

Input:  
Price = [90, 80, 70, 60, 50]
    K = 1
Output:  0
Not possible to earn. 
There are various versions of the problem. If we are allowed to buy and sell only once, 
then we can use Maximum difference between two elements algorithm. If we are allowed to make at most 2 transactions, 
we can follow approach discussed here. If we are allowed to buy and sell any number of times, we can follow approach discussed
*/

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int get_max_share_return(int arr[], int N, int K, pii** pi)
{
	int res, max = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			pi[i][j] = make_pair(-1,-1);
	}
	/*
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			if(i > 0){
				if(pi[i-1][i].first < (arr[j] - arr[i])){
					if(min(min(pi[i-1][j-1].first,pi[i-1][j].first), pi[i][j-1].first) < (arr[j] - arr[i]))
						pi[i][j].first = (arr[j] - arr[i]);
					else
						pi[i][j].first = min(min(pi[i-1][j-1].first,pi[i-1][j].first), pi[i][j-1].first);
				} else
					pi[i][j].first = min(min(pi[i-1][j-1].first,pi[i-1][j].first), pi[i][j-1].first);
			} else {
				if (j == 0)
					pi[i][j].second = 0;
				else {
					if((arr[j] - arr[i]) > pi[i][j].second){
						pi[i][j].second = (arr[j] - arr[i]);
					}
				}
			}
			if(pi[i][j].first > pi[i][j].second)
				swap(pi[i][j].first, pi[i][j].second);
			if((pi[i][j].first + pi[i][j].second)> max)
				max = pi[i][j].first + pi[i][j].second;
		}
	}
	*/

	typedef vector<int> vi;
	vi vec[N][N];
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			if (i > 0){
				
				vec[i][j] = vec[i-1][i];
				if(vec[i-1][i].size() == K){
					if(vec[i][j][0] < (arr[j] - arr[i])){
						vec[i][j][0] = arr[j] - arr[i];
					}
				} else {
					vec[i][j].push_back(arr[j] - arr[i]);
				}
			
			} else {
				
				if(j == 0)
					vec[i][j].push_back(0);
				else{
					if((vec[i][j-1].size() > 0 && vec[i][j-1][0]) < (arr[j] - arr[i]))
						vec[i][j].push_back(arr[j] - arr[i]);
				}
			
			}
			int sum = 0;
			sort(vec[i][j].begin(), vec[i][j].end()); // + vec[i][j].size());
			for(int k = 0; k < vec[i][j].size(); k++){
				sum += vec[i][j][k];
			}
			if(sum > max)
				max = sum;
		}
	}

	return max;
}

int main()
{
	ifstream fin;
	fin.open("shares.in");
	int num_test;
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++){
		int N, K;
		fin >> N >> K;
		int* arr = new int[N];
		for(int i = 0; i < N; i++)
			fin >> arr[i];

		pii** pi = new pii*[N];
		for(int i = 0; i < N; i++)
			pi[i] = new pii[N];
		int res = get_max_share_return(arr,N,K,pi);
		cout << "Case #" << iter+1 << ": " << res << endl;
	}
	return 0;
}
