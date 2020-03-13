#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *a[])
{
    //Write code here
	ifstream fin;
	fin.open("data1.in");
    int T;
    fin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        fin >> N;
        multimap<int, bool> player, villain;
        for (int i = 0; i < N; i++) {
            int en;
            fin >> en;
            villain.insert(make_pair(en, true));
        }
        for (int i = 0; i < N; i++) {
            int en;
            fin >> en;
            player.insert(make_pair(en, true));
        }

        map<int, bool> :: iterator it2 = villain.begin();
        int count = 0;
        for(map<int, bool> :: iterator it1 = player.begin(); it1 != player.end(), it2 != villain.end(); it1++, it2++) {
            if (it1->first > it2->first) {
                count++;
            } else {
                break;
            }
        }

        if (count == N) {
            cout << "WIN\n";
        } else {
            cout << "LOSE\n";
        }
    }

    return 0;
}
