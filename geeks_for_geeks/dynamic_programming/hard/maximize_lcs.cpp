#include<bits/stdc++.h>

using namespace std;


int max_lcs_length(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int row, col;
	row = min(len1, len2);
	col = max(len1, len2);
	int** arr = new int*[row + 1];
	for(int i = 0; i <= row; i++){
		arr[i] = new int[col + 1];
		for(int j = 0; j <= col; j++)
			arr[i][j] = 0;
	}

	int maxi = 0, count = 0, res = 0;
	for(int i = 1; i <= row; i++){
		count = 0;
		for(int j = 1; j <= col; j++){
			if(str1[i-1] == str2[j-1]){
				arr[i][j] = arr[i - 1][j - 1] + 1;
				count = 0;
			} else if (arr[i - 1][j] >= arr[i][j - 1]){
				arr[i][j] = arr[i - 1][j];
				if(arr[i][j] > maxi){
					maxi = arr[i][j];
					count = 0;
				}
				count++;

			} else {
				count = 0;
				arr[i][j] = arr[i][j - 1];
			}
		}
		res = max(res, count);
	}

	return res;
}


int main()
{
	int num_test;
	ifstream fin;
	fin.open("lcs.in");
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++){
		char* str1 = new char[100];
		char* str2 = new char[100];
		memset(str1, '\0', 100);
		memset(str2, '\0', 100);
		fin >> str1 >> str2;
		if(strlen(str1) > strlen(str2))
			swap(str1, str2);
		int res = max_lcs_length(str1, str2);
		cout << "Case #" << iter + 1 << ": " << res << endl;
	}

	return 0;
}
