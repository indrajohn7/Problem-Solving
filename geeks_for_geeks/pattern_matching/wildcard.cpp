#include<bits/stdc++.h>

using namespace std;
#define SIZE 100


bool get_wild_card_pattern(string text, char* pattern)
{
	const char* str = new char[SIZE];
	//memset(str, '\0', SIZE);
	str = text.c_str();
	int tlen, plen;
	tlen = strlen(str);
	plen = strlen(pattern);
	bool arr[plen][tlen];
	for(int i = 0; i < plen; i++){
		for(int j = 0; j < tlen; j++){
			if(isalpha(pattern[i])){
				if(pattern[i] == str[j]){
					if(j == 0 || i == 0)
						arr[i][j] = true;
					else
						arr[i][j] = arr[i - 1][j - 1];
				}
			} else if(pattern[i] == '*'){
				if(j == 0)
					arr[i][j] = true;
				if(arr[i - 1][j - 1] || arr[i][j - 1])
					arr[i][j] = true;
				else
					arr[i][j] = false;
			} else if(pattern[i] == '?'){
				arr[i][j] = arr[i - 1][j - 1];

			} else{
				arr[i][j] = false;
			}
		}
	}

	return arr[plen - 1][tlen - 1];
}


int main()
{
	int num_test;
	ifstream fin;
	fin.open("wild.in");
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++){
		string text;
		int N;
		fin >> text >> N;
		char** arr = new char*[N];
		for(int i = 0; i < N; i++){
			arr[i] = new char[SIZE];
			memset(arr[i], '\0', SIZE);
			fin >> arr[i];
		}
		cout << "Case #" << iter + 1 << ": " << text << endl;
		for(int i = 0; i < N; i++){
			bool res = get_wild_card_pattern(text, arr[i]);
			cout << arr[i] << " :: " << (res ? "Yes" : "No") << endl;
		}
	}

	return 0;
}
