#include<bits/stdc++.h>

using namespace std;

typedef pair<char, int> pci;
typedef vector<pci> vci;

int get_all_string_combinations(char* arr)
{
	int len = strlen(arr);
	typedef vector<vci> vcii;
	vector<vcii> vec;
	vcii temp;
	map<char, int> work;
	for(int i = 0; i < len; i++){
		pair<char, int> p = make_pair(arr[i], i);
		vci t;
		t.push_back(p);
		temp.push_back(t);
		if(work.find(arr[i]) == work.end())
			work[arr[i]] = 1;
		else
			work[arr[i]]++;
	}
	vec.push_back(temp);

	int max_count = 1, oper = 0;
	for(map<char, int>::iterator it = work.begin(); it != work.end(); it++){
		max_count *= it->second;
	}
	int count = 0;
	vcii res;
	while(oper < max_count){
		temp.clear();
		int last = vec[vec.size() - 1].size();
		for(int i = 0; i < last; i++){
			int latest = vec[vec.size() - 1][i].size();
			char ch = vec[vec.size() - 1][i][latest - 1].first;
			int pos = vec[vec.size() - 1][i][latest - 1].second;
			map<char, int>::iterator it = work.begin();
			it = work.find(ch);
			char second_ch = (++it)->first;
			it = work.end();
			char end_elem = (--it)->first;

			for(int j = pos + 1; j < len; j++){
				vci t = vec[vec.size() - 1][i];
				if (arr[j] == ch || arr[j] == second_ch){
					pair<char, int> p = make_pair(arr[j], j);
					t.push_back(p);
				}
				
				if(end_elem == arr[j]){
					count++;
					res.push_back(t);
				}
				temp.push_back(t);
			}
		}
		vec.push_back(temp);
		oper++;
	}

	return count;
}

int main()
{
	int num_test;
	ifstream fin;
	fin.open("string.in");
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++){
		char arr[100];
		memset(arr, '\0', 100);
		fin >> arr;
		int res  = get_all_string_combinations(arr);
		cout << "Case #" << iter + 1 << ": " << res << endl;
	}

	return 0;
}
