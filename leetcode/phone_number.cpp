#include<bits/stdc++.h>

using namespace std;

vector<string> letterCombinations(string digits) {
        typedef vector<char> vc;
		map<int, vc> vmap;
        int count = 0;
        for (int i = 2; i <= 9; i++) {
            int num;
            if (i  == 7 || i == 9) {
                num = 4;
            } else {
                num = 3;
            }
            vector<char> vec;
            for (int j = 0; j < num ; j++) {
                char ch = 'a' + count;
                vec.push_back(ch);
                count++;
            }
            vmap[i] = vec;
        }
        vector<string> res;
        for (int i = 0; i < digits.length(); i++) {
            vector<string> temp;
			int num = digits[i] - '0';
            vector<char> vec = vmap[num];
            if (res.size() == 0) {
                for (int j = 0; j < vec.size(); j++) {
                    string s(1, vec[j]);
                    temp.push_back(s);
                }
            } else {
                for (int j = 0; j < res.size(); j++) {
                    for (int k = 0; k < vec.size(); k++) {
                    	string str = res[j];
                        str.push_back(vec[k]);
                        temp.push_back(str);
                    }
                }
            }
            res = temp;
        }
        
        return res;
}

int main()
{
	vector<string> vec = letterCombinations("23");
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "\t";
	}
	cout << endl;

	return 0;
}
