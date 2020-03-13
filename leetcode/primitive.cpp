#include<bits/stdc++.h>

using namespace std;

string removeOuterParentheses(string S) {
        const char* str = S.c_str();
        int N = S.length();
        vector<char*> vec;
        int opened, closed, first, last;
        opened = closed = 0;
        for (int i = 0; i < N; i++) {
            if (opened == 0) {
                first = i;
            }
            if (str[i] == '(') {
                opened++;
            } else {
                closed++;
            }
            
            if (opened == closed) {
                last = i;
                opened = closed = 0;
                char* res = new char[last - first + 1];
                memset(res, '\0', (last - first + 1));
                strncpy(res, str + first, last - first + 1);
                vec.push_back(res);
            }
            
        }
        char* final_str = new char[N];
        memset(final_str, '\0', N);
        for (int i = 0; i < vec.size(); i++) {
            char* temp = vec[i];
            //temp[0] = '\0';
            //temp[strlen(temp) - 1] = '\0';
            cout << temp << " :: ";
            if (i == 0)
				strncpy(final_str, temp + 1, strlen(temp) - 2);
			else
				strncat(final_str, temp + 1, strlen(temp) - 2);
        }
        string ret(final_str);
        cout << endl;
        return ret;
}

int main()
{
	ifstream fin;
	fin.open("prim.in");
	int T;
	fin >> T;

	for (int t = 0; t < T; t++) {
		string input;
		fin >> input;
		string res = removeOuterParentheses(input);

		cout << res << endl;
	}

	return 0;
}
