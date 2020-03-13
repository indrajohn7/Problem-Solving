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

typedef vector<int> vi;

int main(int argc, char *a[])
{
    //Write code here
    ifstream fin;
	fin.open("a.in");
	int T;
    fin >> T;
	//cout << "Test: " << T << endl;
    for (int test = 0; test < T; test++) {
        int r, c;
        fin >> r >> c;
        vector<int> phase;
        vector<int> state;
        int phase_sum, state_sum;
        map<int, vi> phase_map;
        map<int, vi> state_map;
        phase_sum = state_sum = 0;
		//cout << r << "::" << c << endl;
        for (int i = 0; i < r; i++) {
            int temp;
            fin >> temp;
            //cout << temp << endl;
            phase.push_back(temp);
            phase_sum += temp;
            if (phase_map.find(temp) == phase_map.end()) {
                vector<int> v;
                v.push_back(i);
                phase_map[temp] = v;
            } else {
                phase_map[temp].push_back(i);
            }
        }
        for (int i = 0; i < c; i++) {
            int temp;
            fin >> temp;
            state.push_back(temp);
            state_sum += temp;
            //cout << temp <<endl;
            if (state_map.find(temp) == state_map.end()) {
                vector<int> v;
                v.push_back(i);
                state_map[temp] = v;
            } else {
                state_map[temp].push_back(i);
            }
        }
        vector<int> used_phase;
        used_phase.assign(r, 0);
        vector<int> used_state;
        used_state.assign(c, 0);
        if (phase_sum != state_sum) {
            cout << "NO" << endl;
        } else {
            bool flag = true;
            map<int, vi> :: reverse_iterator it3 = state_map.rbegin();
            for (map<int, vi> :: reverse_iterator it = phase_map.rbegin(); it != phase_map.rend(); it++) {
                vector<int> v = it->second;
                int win_val = it->first;
                //cout << "WIN_VAL: " << win_val << endl;
                for (int i = 0; i < v.size(); i++) {
                    int phase_val = v[i];
                    int count = 0;
                    for (map<int, vi> :: reverse_iterator it2 = it3; it2 != state_map.rend(); it2++) {
                        it3 = it2;
                        vector<int> u = it2->second;
                        for (int j = 0; (j < u.size()); j++) {
                            int state_val = u[j];
                            if (count >= win_val) {
                                break;
                            }
                            if (used_state[state_val] < state[state_val]) {
                                count++;
                                used_state[state_val]++;
                            }
                        }
                        if (count >= win_val) {
                            break;
                        }
                    }
                    //cout << "COUNT: " << count << endl;
                    if (count != win_val) {
                        flag = false;
                        cout << "NO" << endl;
                        break;
                    }
                    
                }
                if (flag) {
                    cout << "YES" << endl;
					break;
                }
            }
        }

    }

    return 0;
}

