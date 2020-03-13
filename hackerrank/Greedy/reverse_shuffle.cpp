#include <bits/stdc++.h>

using namespace std;

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {

    char* str = new char[s.length() / 2];
    memset(str, '\0', s.length() / 2);
    map<char, int> vmap;
    for (string :: iterator it = s.begin(); it != s.end(); it++) {
        if (vmap.find(*it) == vmap.end()) {
            vmap[*it] = 1;
        } else {
            vmap[*it] += 1;
        }
    }
    int idx = 0;
    string :: reverse_iterator it2 = s.rbegin();
    string :: reverse_iterator it3 = s.rbegin();
    string :: reverse_iterator it4 = s.rbegin();
    map<char, int> :: iterator it = vmap.begin();
    int char_count = 0;
	for (string :: reverse_iterator it3 = s.rbegin(); it3 != s.rend(); it3++) {
		char c = it->first;
		if (*it3 == c) {
			it4 = it3;
			break;
		}
	}
	map<char, int> vmap2;
	map<char, int> vmap3;
    it = vmap.begin();

    for (string :: reverse_iterator it2 = s.rbegin(); it2 != s.rend(); it2++) {
        char c = it->first;
		int count = it->second;
		map<char, int> :: iterator iter = vmap2.find(*it2);
		map<char, int> :: iterator iter2 = vmap3.find(*it2);
		if (*it2 == c) {
			if (iter == vmap2.end()) {
				vmap2[*it2] = 1;
				str[idx++] = *it2;
			} else if (iter->second < it->second / 2){
				iter->second += 1;
				str[idx++] = *it2;
			} 
			if (vmap2[*it2] == count / 2){
				++it;
			}
		} else {
			if (iter2 == vmap3.end()) {
				vmap3[*it2] = 1;
			} else if (iter2->second < vmap.find(*it2)->second / 2) {
				iter2->second += 1;
			} else {
				if (iter == vmap2.end()) {
					vmap2[*it2] = 1;
					str[idx++] = *it2;
				} else {
					iter->second += 1;
					str[idx++] = *it2;
				}
			}
		}
    }
    cout << str << endl;
    string ret(str);

    return ret;
}


int main()
{
	ifstream fin;
	fin.open("shuffle.in");
	int T;
	fin >> T;
	for (int t = 0; t < T; t++) {
		string str;
		fin >> str;
		string res = reverseShuffleMerge(str);
		cout << res << endl;
	}

	return 0;
}
