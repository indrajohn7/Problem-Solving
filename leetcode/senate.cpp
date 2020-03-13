#include<bits/stdc++.h>

using namespace std;

string predictPartyVictory(string senate) {
        
        char winner = '0';
        int found1, found2;
        found1 = found2 = 0;
        while (1) {
            for (string :: iterator it = senate.begin(); it != senate.end(); it++) {
                int pos = it - senate.begin();
                cout << *it << endl;
				if (*it == '\0' || pos >= senate.length()) {
					it = senate.begin();
					//continue;
					pos = 0;
				}
                if (*it == 'R') {
                    found1 = senate.find('D', pos + 1);
                    
                    if (found1 == string::npos) {
                        found2 = senate.find('D', 0);
                        if (found2 == string::npos) {
                            winner = 'R';
                            break;
                        } else {
                            senate.erase(senate.begin() + found2);
                        }
                    } else {
                        senate.erase(senate.begin() + found1);
                    }
                } else {
                    found1 = senate.find('R', pos + 1);
                    
                    if (found1 == string::npos) {
                        found2 = senate.find('R', 0);
                        if (found2 == string::npos) {
                            winner = 'D';
                            break;
                        } else {
                            senate.erase(senate.begin() + found2);
                        }
                    } else {
                        senate.erase(senate.begin() + found1);
                    }
                }
            } 
            if (winner != '0')
                break;
        }
        if (winner == 'R') {
            return "Radiant";
        } else {
            return "Dire";
        }
        
       // (winner == 'R'
}


int main()
{
	ifstream fin;
	fin.open("senate.in");
	int T;
	fin >> T;
	for (int t = 0; t < T; t++) {
		string str;
		fin >> str;
		string res = predictPartyVictory(str);
		cout << res << endl;
	}

	return 0;
}
