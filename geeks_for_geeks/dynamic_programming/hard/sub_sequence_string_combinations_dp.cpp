#include<bits/stdc++.h>

using namespace std;

typedef pair<char, int> pci;
typedef vector<pci> vci;

bool is_char_first_elem(char c, map<char, int> work)
{
	if(c == work.begin()->first)
		return true;
	else

		return false;
}

bool is_concat_possible(char* str, char c, map<char, int> work)
{
	map<char, int> :: iterator it = work.begin();
	it = work.find(str[strlen(str) - 1]);
	if(str[strlen(str) - 1] == c || (++it)->first == c)
		return true;
	else
		return false;
}

int get_all_string_combinations(char* arr)
{
	typedef vector<char*> vc;
	vector<vc> vec;
	int len = strlen(arr);
	char str[2];
	memset(str, '\0', 2);
	str[0] = arr[0];
	vc temp;
	temp.push_back(str);
	vec.push_back(temp);
	map<char, int> work;
	map<char, int> :: iterator it;
	
	for(int i = 0; i < len; i++){
		if(work.find(arr[i]) == work.end()){
			work[arr[i]] = 1;
		} else {
			work[arr[i]]++;
		}
	}
	
	vc res;
	it = work.end();
	char last_elem = (--it)->first;
	for(int i = 1; i < len; i++){
		temp.clear();
		if(is_char_first_elem(arr[i], work))	{
			char* str2 = new char[2];
			memset(str2, '\0', 2);
			str2[0] = arr[i];
			temp.push_back(str2);
		}
		for(int j = i - 1; j >= 0; j--){
			
			for(int k = 0; k < vec[j].size(); k++){
				char* stream = new char[100];
				memset(stream, '\0', 100);
				if(is_concat_possible(vec[j][k], arr[i], work)){
					strncpy(stream, vec[j][k], strlen(vec[j][k]));
					char* str1 = new char[2];
					memset(str1, '\0', 2);
					str1[0] = arr[i];
					strncat(stream, str1, 1);
					temp.push_back(stream);

					if(last_elem == arr[i]){
						res.push_back(stream);
					}
				}
			}
		}
		vec.push_back(temp);
	}

	return res.size();
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
