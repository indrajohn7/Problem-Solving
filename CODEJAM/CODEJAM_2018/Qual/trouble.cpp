#include<bits/stdc++.h>

using namespace std;


int main()
{
	ifstream fin;
	fin.open("trouble.in");
	int Num_test;

	fin >> Num_test;
	for(int iter = 0; iter < Num_test; iter++) {
		int N;
		fin >> N;
		long long int* arr = new long long int[N];

		for(int i = 0; i < N; i++) {
			fin >>arr[i];
		}
		
		for(int j = 0; j < N - 2; j++) {
			for (int i = 0; i < N - 2; i++) {
				if (arr[i] > arr[i + 2])
					swap(arr[i], arr[i + 2]);
			}
		}

		int res = -1;

		for(int i = 0; i < N - 1; i++){
			if (arr[i] > arr[i + 1]){
				res = i;		
				break;
			}
		}
		cout << "Case #" << iter + 1 << ": ";
		if (res == -1)
			cout << "OK" << endl;
		else
			cout << res << endl;
	}

	return 0;
}


