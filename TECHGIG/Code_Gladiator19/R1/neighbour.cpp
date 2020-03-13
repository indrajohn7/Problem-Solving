/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *a[])
{
    //Write code here
	ifstream fin;
	fin.open("data2.in");
    int T;
    fin >> T;
    typedef vector<int> vec;
    typedef pair<int, int> pi;
    typedef pair<pi, vec> pii;
    typedef vector<pii> vpi;

    for (int t = 0; t < T; t++) {
        int N;
        fin >> N;
        int* input = new int[N];
        pii** arr = new pii*[N];
        for (int i = 0; i < N; i++) {
            int val;
            fin >> val;
            input[i] = val;
            arr[i] = new pii[N];
        }
        vector<vec> vvec;
        int max_val = 0;
        for (int i = 0; i < N / 2 + 1; i++) {
            for (int j = i; j < N; j++) {
                if (j < i) {
                    vector<int> v;
                    v.push_back(0);
                    arr[i][j] = make_pair(make_pair(-1, -1), v);
                } else if (j == i || j == i + 1){
                    vector<int> v;
                    v.push_back(input[i]);
                    arr[i][j] = make_pair(make_pair(i, input[i]), v);
                    //max_val = input[i];
                } else {
                    
                    int last_idx, last_sum, second_last_idx, second_last_sum;
                    last_idx = arr[i][j - 1].first.first;
                    last_sum = arr[i][j - 1].first.second;
                    second_last_idx = arr[i][j - 2].first.first;
                    second_last_sum = arr[i][j - 2].first.second;
					if ((input[j] > (input[j] + second_last_sum)) && (input[j] > last_sum)) {
                    	vector<int> v;
						v.push_back(input[j]);
						int sum = input[j];
						arr[i][j] = make_pair(make_pair(j, sum), v);
					} else if ((input[j] + second_last_sum) > last_sum) {
                        vector<int> v = arr[i][j - 2].second;
                        v.push_back(input[j]);
                        int sum = second_last_sum + input[j];
                        arr[i][j] = make_pair(make_pair(j, sum), v);
                    } else {
                        vector<int> v = arr[i][j - 1].second;
                        //v.push_back(input[j]);
                        int sum = last_sum;
                        arr[i][j] = make_pair(make_pair(last_idx, sum), v);
                    }
                }
                
            }
            if (i == 0) {
                max_val = arr[i][N - 1].first.second;
                vvec.push_back(arr[i][N - 1].second);
            } else if (arr[i][N - 1].first.second >= max_val) {
                max_val = arr[i][N - 1].first.second;
                vvec.push_back(arr[i][N - 1].second);
            }
            
        }
        int idx = 0;
        int mini = -1;
        for (int i = 0; i < vvec.size(); i++) {
            sort(vvec[i].begin(), vvec[i].end());
            if (vvec[i][0] > mini) {
                mini = vvec[i][0];
                idx = i;
            }
        }

        for(int i = 0; i < vvec[idx].size(); i++)
            cout << vvec[idx][i];
		cout << endl;
    }

    return 0;
}

