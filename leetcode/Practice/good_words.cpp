#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vector<int> solve(string A, vector<string> &B) {

    set<string> good_words;
    string temp = A;
    string :: iterator it = A.begin();
    while (temp.find('_') != string :: npos) {
        it = temp.begin();
        int pos = temp.find('_');
        string str;
        str.insert(str.begin(), temp.begin(), temp.begin() + pos);
        temp.erase(temp.begin(), temp.begin() + pos + 1);
        good_words.insert(str);
        //cout << str << endl;
		//cout << good_words << endl;
    }
    good_words.insert(temp);

    for (set<string> :: iterator it = good_words.begin(); it != good_words.end(); it++) {
        cout << *it << endl;
    }
    map<int, vi> vmap;
    for (int i = 0; i < B.size(); i++) {
        const char* str = B[i].c_str();
        temp = B[i];
        int count = 0;
        while (temp.find('_') != string :: npos) {
            it = temp.begin();
            int pos = temp.find('_');
            string str;
			cout << temp << endl;
            str.insert(str.begin(), temp.begin(), temp.begin() + pos);
			cout << str << endl;
            temp.erase(temp.begin(), temp.begin() + pos + 1);
            if (good_words.find(str) != good_words.end()) {
                count++;
            }
        }
        if (good_words.find(temp) != good_words.end()) {
			cout << temp << endl;
            count++;
        }
		cout << "COUNT: " << count << endl;
        if (vmap.find(count) == vmap.end()) {
            vector<int> v;
            v.push_back(i);
            vmap[count] = v;
        } else {
            vmap[count].push_back(i);
        }
    }
    vector<int> vec;
    for (map<int, vi> :: reverse_iterator it = vmap.rbegin(); it != vmap.rend(); it++) {
        vector<int> v = it->second;
        for (int i = 0; i < v.size(); i++) {
            vec.push_back(v[i]);
        }
    }

    return vec;
}


int main()
{
    string A = "pool_fridge_wifi";
    vector<string> B; // = ["smart_guy", "girl_and_boy_play", "play_ground"];
    B.push_back("water_in_pool");
    B.push_back("pond_fridge_drink");
    B.push_back("pool_wifi_drink");
    vector<int> vec = solve(A, B);
    for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
}
