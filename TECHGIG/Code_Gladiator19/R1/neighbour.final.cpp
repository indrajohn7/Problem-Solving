/* Read input from STDIN. Print your output to STDOUT*/

#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *a[])
{
    //Write code here
	ifstream fin;
	fin.open("data2.in");
     int T;
    fin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        fin >> N;
        int* input = new int[N];
        
        multimap<int, int> vmap;
        typedef pair<int, int> pii;
        multimap<pii, int> vmapii;
        multiset<int> sec;

        int zero_count, neg_count;
        zero_count = neg_count = 0;
        for (int i = 0; i < N; i++) {
            int val;
            fin >> val;
            input[i] = val;
            vmap.insert(make_pair(val, i));
            if (val == 0)
                zero_count++;
            else if (val < 0 )
                neg_count++;
        }
    //    map<int, int> :: iterator it = vmap.begin();
        map<int, int> :: reverse_iterator iter = vmap.rbegin();
        if (zero_count + neg_count == N) {
            if (neg_count == N) {
               // ++iter;
                sec.insert(iter->first);
            } else {
                sec.insert(0);
            }
        } else {
            int sum = 0;
            for (iter = vmap.rbegin(); iter != vmap.rend(); ++iter) {
                map<int, int> locate;
                multiset<int> temp_sec;
                int temp_sum = iter->first;
                temp_sec.insert(iter->first);
                int idx = iter->second;
            //    pair<int, int> p1 = make_pair(idx - 1, idx + 1);
            //    pair<int, int> p2 = make_pair(idx + 1, idx - 1);
                locate[idx - 1] = 1;
                locate[idx + 1] = 1;
                locate[idx] = 1;
                if (iter->first <= 0) {
                    break;
                }
                for (map<int, int> :: reverse_iterator it2 = iter; it2 != vmap.rend(); ++it2) {
                    
                    if ((temp_sum + it2->first) > temp_sum && locate.find(it2->second) == locate.end()) {
                        temp_sum = temp_sum + it2->first;
                        temp_sec.insert(it2->first);
                        idx = it2->second;
                        locate[idx - 1] = 1;
                        locate[idx + 1] = 1;
                        locate[idx] = 1;
                    }
                }
                if (temp_sum > sum) {
                    sum = temp_sum;
                    sec.clear();
                    sec = temp_sec;
                } if (temp_sum == sum) {
                    set<int> :: iterator it = sec.begin();
                    set<int> :: iterator it1 = temp_sec.begin();
                    if (*it1 > *it) {
                        sec.clear();
                        sec = temp_sec;
                    }
                }
                temp_sec.clear();
                locate.clear();
            }
        }
        for (multiset<int> :: iterator it = sec.begin(); it != sec.end(); it++) {
            cout << *it;
        }
        cout << endl;
        
    }

    return 0;
}
