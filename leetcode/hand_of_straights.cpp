#include<bits/stdc++.h>

using namespace std;

bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size() % W) {
            return false;
        }
        
        typedef stack<int> sint;
        map<int, sint> vmap;
        for (int i = 0; i< hand.size(); i++) {
            if (vmap.find(hand[i]) == vmap.end()) {
                sint temp_stack;
                temp_stack.push(i);
                vmap.insert(make_pair(hand[i], temp_stack));
            } else {
                vmap[hand[i]].push(i);
            }
        }
        int count = hand.size() / W;
        map<int, sint> :: iterator it = vmap.begin();
        while (count--) {
            while (it->second.size() == 0){
                map<int, sint> :: iterator iter = it;
                ++it;
                vmap.erase(iter->first);
            }
            map<int, sint> :: iterator it2 = it;
            int rep = 1;
            while (rep != W) {
                int num = it2->first;
                if (vmap.find(num + 1) != vmap.end() && 
                    vmap.find(num + 1)->second.size() != 0) {
                    rep++;
                    it2->second.pop();
                    it2 = vmap.find(num + 1);
                } else {
                    return false;
                }
            }
            it2->second.pop();
        }
        return true;
}

int main()
{
	ifstream fin;
	fin.open("hand.in");
	int T;
	fin >> T;
	for (int t = 0; t < T; t++) {
		int N, W;
		fin >> N >> W;
		vector <int> vec;
		for (int i = 0; i < N; i++) {
			int num;
			fin >> num;
			vec.push_back(num);
		}
		bool res = isNStraightHand(vec, W);
		if (res)
			cout << "True" << endl;
		else
			cout << "Flase" << endl;
	}

	return 0;
}

