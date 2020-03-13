#include<bits/stdc++.h>

using namespace std;

string smallestSubsequence(string text) {
        string str;
        set <char> sec;
        for (int i = 0; i < text.length(); i++) {
            sec.insert(text[i]);
        }
        /*
        for (set<char> :: iterator it = sec.begin(); 
            it != sec.end(); it++) {
            
            cout << *it << " ";
        }
        cout << endl;
        */
        if (sec.size() == 1) {
            string temp_str(1, *(sec.begin()));
            return temp_str;
        }
        vector<string> vsec;
        
        for (int i = 0; i < text.length() ; i++) {
            
            vector<string> vec;
            vec = vsec;
            for (int j = 0; j < vsec.size(); j++) {
				if (vsec[j].size() == sec.size()){
					continue;
				}
                string temp = vsec[j];
                temp.push_back(text[i]);
                set<char> temp_sec;
                temp_sec.insert(temp.begin(), temp.end());
                if (temp_sec == sec && temp.length() == sec.size()) {
                    //cout << temp << endl;
                    if (str.length() == 0) {
                        str = temp;
                    } else if (str > temp) {
                        str = temp;
                    }
                }
                vec.push_back(temp);
            }
            
            string s(1, text[i]);
            vec.push_back(s);
            vsec = vec;
        }
        
        return str;
        
    }

int main()
{
	string str = smallestSubsequence("baababaaaaababbbbbbaababaababa");
	cout << "RESULT: " << str << endl;
	str = smallestSubsequence("dbdcbcbeecbbdcdebadbcecccdbaabaeeacbbcab");
	cout << "RESULT: " << str << endl;
	return 0;
}

