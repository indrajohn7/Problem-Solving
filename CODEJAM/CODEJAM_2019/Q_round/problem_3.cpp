#include<bits/stdc++.h>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("data3.in");
	int T;
	fin >> T;
	for (int t = 0; t < T; t++) {
		unsigned long long N, L;
		fin >> N >> L;
		vector<unsigned long long> input;
		map<unsigned long long, char> vmap;
		typedef pair<unsigned long long, unsigned long long> pll;
		vector<pll> vpl;
		int last_num = 0;
		for (int i = 0; i < L; i++) {
			int num;
			fin >> num;
			input.push_back(num);
			unsigned long long first, second;
			if (i == 0) {
				int sq = sqrt(num);
				if (sq % 2 == 0)
					sq += 1;

				for(int j = sq; j >= 3; j -= 2) {
					if ((num % j) == 0) {
						first = j;
						second = (num / j);
						int maxi = max(first, second);
						int mini = min(first, second);
						vpl.push_back(make_pair(mini, maxi));
						vmap[first] = 'A';
						vmap[second] = 'A';
						last_num = maxi;
						break;
					}
				}
			} else {
				first = last_num;
				second = num / first;
				last_num = second;
				vpl.push_back(make_pair(first, second));
				vmap[first] = 'A';
				vmap[second] = 'A';
			}
			
		}
		int count = 0;
		for (map<unsigned long long, char> :: iterator it = vmap.begin(); it != vmap.end(); it++) {
			it->second = 'A' + count++;
		}
		char* out = new char[L + 1];
		memset(out, '\0', L + 1);
		for (int i = 0; i < vpl.size(); i++) {
			
			int first, second;
			first = vpl[i].first;
			second = vpl[i].second;
			
			if (i == 0) {
				out[i] = vmap.find(first)->second;
				out[i + 1] = vmap.find(second)->second;
			} else {
				out[i + 1] = vmap.find(second)->second;
				
			}
			//strncat(out, (char*)vmap.find(first)->second, 1);
			//strncat(out, (char*)vmap.find(second)->second, 1);
		}
		cout << "Case #" << (t + 1) << ": " << out << endl;
	}
		

	return 0;
}
