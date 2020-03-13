#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the pylons function below.
int pylons(int k, vector<int> arr) {

    int last_idx, key_idx, left_idx, right_idx, count;
    left_idx = right_idx = last_idx = key_idx = count = 0;
    k -= 1;
    while ((key_idx + k) < arr.size() && last_idx < arr.size()) {
        if (last_idx + k < arr.size()) {
            if (arr[last_idx + k] == 1) {
                count++;
                key_idx = last_idx + k;
                last_idx = key_idx + k + 1;
            //last_idx++;
            } else {
                bool flag = false;
                for (int j = last_idx + k; j > key_idx; j--) {
                    if (arr[j] == 1) {
                        count++;
                        key_idx = j;
                        last_idx = key_idx + k + 1;
                        flag = true;
						break;
                    }
                }
                if (!flag) {
                    return -1;
                }
            }
        } else {
            bool flag = false;
            for (int j = arr.size() - 1; j >= arr.size() - k - 1; j--) {
                if (arr[j] == 1) {
                    count++;
                    key_idx = j;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                return -1;
            }
        }
        cout << key_idx <<endl;
        cout << count <<endl;
    }
 //   if (key_idx + k >= arr.size()) {
        return count;
  //  } 
    //return 
}

int main()
{
	ifstream fin;
	fin.open("goodland.in");
	int T;
	fin >> T;
	for (int t = 0; t < T; t++) {
		int N, K;
		fin >> N >> K;
		vector<int> vec;
		for (int i = 0; i < N; i++) {
			int temp;
			fin >> temp;
			vec.push_back(temp);
		}
		int res = pylons(K, vec);
		cout << res << endl;
	}

	return 0;
}

