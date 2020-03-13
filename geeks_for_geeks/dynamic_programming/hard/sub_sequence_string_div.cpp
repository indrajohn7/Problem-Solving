#include<bits/stdc++.h>

using namespace std;

int get_num(char* str, int s, int d, int length)
{
	int val = -1;
	if((d-s) != length)
		return val;

	for(int i = s; i <= d; i++){
		val = (val*10) + (str[i]-'0');
	}

	return val;
}

int get_max_divisors(char* str, int num)
{
	int len = strlen(str);
	typedef pair<int, int> pii;
	typedef vector<pii> vi;
	vector<vi> vec;
	int stream = 1, count = 0;
	vector<pii> temp;
	for (int i = 0; i < len; i++){
		int val = (str[i] - '0');
		if((val % num) == 0)
			count++;
		temp.push_back(make_pair(val, i));

	}
	
	vec.push_back(temp);
	
	while(stream < len) {
		temp.clear();
		
		int last = vec[vec.size()-1].size();

		for(int i = 0; i < last; i++) {

			int pos = vec[vec.size()-1][i].second;
			int pos_val = vec[vec.size()-1][i].first;

			for(int j = (pos + 1); j < len; j++){
				int val = (pos_val * 10) + (str[j]- '0');
				if(val != -1 && (val % num) == 0)
					count++;
				temp.push_back(make_pair(val, j));
			}
		}
		vec.push_back(temp);
		stream++;
	}

	return count;
}


int main()
{
	int num_test;
	ifstream fin;
	fin.open("subsequence.in");
	fin >> num_test;

	for(int iter = 0; iter < num_test; iter++) {
		int div;
		char str[100];
		memset(str,'\0',sizeof(str));
		fin >> str >> div;
		int res = get_max_divisors(str,div);
		cout << "Case #" << iter+1 << ": " << res << endl;
	}
	return 0;
}
