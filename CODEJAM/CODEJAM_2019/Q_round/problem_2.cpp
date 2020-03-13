#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
struct path {
	string dir;
	vector<pii> vpi;
};

int main()
{
	ifstream fin;
	fin.open("data2.in");
	int T;
	fin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		fin >> N;
		struct path lyndia, indra;
		string str;
		fin >> str;
		lyndia.dir = str;
		const char* dir = str.c_str();
		char* out = new char[(2 * N) - 2];
		memset(out, '\0', (2 * N) - 2);

		lyndia.vpi.push_back(make_pair(1, 1));
		indra.vpi.push_back(make_pair(1, 1));
		for (int i = 0; i < strlen(dir); i++) {
			char c = dir[i];
			pair<int, int> pi = lyndia.vpi[lyndia.vpi.size() - 1];

			pair<int, int> prev = indra.vpi[indra.vpi.size() - 1];
			if (c == 'S') {
				lyndia.vpi.push_back(make_pair(pi.first + 1, pi.second));
			} else {
				lyndia.vpi.push_back(make_pair(pi.first, pi.second + 1));
			}
			if (prev == pi) {
				if (c == 'S'){
					indra.vpi.push_back(make_pair(prev.first, prev.second + 1));
					strncat(out, "E", 1);
				} else {
					indra.vpi.push_back(make_pair(prev.first + 1, prev.second));
					strncat(out, "S", 1);
				}
			} else {
				if (prev.first + 1 < N && make_pair((prev.first + 1), prev.second) == lyndia.vpi[lyndia.vpi.size() - 1]) {
					//South
					indra.vpi.push_back(make_pair(prev.first + 1, prev.second));
					strncat(out, "S", 1);

				} else if (prev.second + 1 < N && make_pair(prev.first, (prev.second + 1)) == lyndia.vpi[lyndia.vpi.size() - 1]) {
				
					indra.vpi.push_back(make_pair(prev.first, prev.second + 1));
					strncat(out, "E", 1);
				} else {

					
					if (c == 'S' && prev.first + 1 <= N) { // South
						indra.vpi.push_back(make_pair(prev.first + 1, prev.second));
						strncat(out, "S", 1);
					
					} else if (c == 'E' && prev.second + 1 <= N) { //East
						indra.vpi.push_back(make_pair(prev.first, prev.second + 1));
						strncat(out, "E", 1);
				
					} else if (prev.first + 1 <= N) { // South
						indra.vpi.push_back(make_pair(prev.first + 1, prev.second));
						strncat(out, "S", 1);
					
					} else if (prev.second + 1 <= N) { //East
						indra.vpi.push_back(make_pair(prev.first, prev.second + 1));
						strncat(out, "E", 1);
				
					}
				}
			}
			
		}
		cout << "Case #" << (t + 1) << ": " << out << endl;
	}
	return 0;
}
