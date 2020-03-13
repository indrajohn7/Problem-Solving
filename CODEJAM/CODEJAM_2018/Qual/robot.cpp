#include<bits/stdc++.h>

using namespace std;

int get_val(char* stream, int curr, int pos)
{
	int sum = 0;
	for(int i = pos; i < strlen(stream); i++) {
		if(stream[i] == 'C')
			curr *= 2;
		else if (stream[i] == 'S')
			sum +=curr;
	}

	return sum;
}

int count(const char* str, char ch)
{
	int res = 0;
	for(int i = 0; i < strlen(str); i++){
		if (str[i] == ch)
			res++;
	}
	return res;
}

int main()
{
	ifstream fin;
	fin.open("robo.in");
	int Num_test;
	fin >> Num_test;

	for(int iter = 0; iter < Num_test; iter++) {
		int D;
		string str;
		fin >> D >> str;
		char* stream = new char[str.length() + 1];
		memset(stream, '\0', str.length() + 1);
		strncpy(stream, str.c_str(), str.length());

		int s_count = count(str.c_str(), 'S');
		int c_count = count(str.c_str(), 'C');
		bool impos = false;
		bool always = false;

		if (s_count > D) impos = true;
		if (c_count ==0 && s_count <=D) always = true;
		else if (s_count == 0) always = true;
		int count = 0;

		if (!(impos || always)) {
			int current_val = 1, hit_count = 0;
			for(int i = 0; i < strlen(stream); i++) {
				
				if (stream [i] == 'C' && stream[i + 1] != '\0' && stream [i+1] == 'S') {
					int val = get_val(stream, current_val * 2, i+2);
					if ((hit_count + val + current_val * 2) > D){
						swap(stream[i], stream[i + 1]);
					//	current_val *= 2;
						count++;
						hit_count += current_val;
					} else {
						current_val *= 2;
						break;
					}
				} else if (stream[i] == 'S') {
					hit_count += current_val;
				} else if (stream[i] == 'C' && stream [i + 1] != '\0' && stream [i + 1] == 'C') {
					char* p = strchr(&stream[i], 'S');
					if (p != NULL) {
						int pos = p - (&stream[i]);
						int cursor = 0;
						char* temp_str = new char[strlen(stream) + 1];
						memset(temp_str, '\0', strlen(stream) + 1);
						memcpy(temp_str, stream, strlen(stream));
					
						int val = get_val(stream, current_val * pow(2,pos), i + pos);
						if ((hit_count + val) > D) {
							int temp_hit, temp_curr;
							temp_hit = hit_count;
							temp_curr = current_val;
								
								swap(temp_str[i + cursor], temp_str[i + pos]);
								temp_hit += temp_curr * pow(2, cursor);
								val = get_val(temp_str, temp_curr * pow(2, cursor), i + cursor);

								strncpy(temp_str, stream, strlen(stream));
							while ((hit_count + val) <= D && stream[i + cursor] != 'S') {

								cursor++;
								swap(temp_str[i + cursor], temp_str[i + pos]);
								//temp_hit = hit_count + temp_curr * pow(2, cursor);
								val = get_val(temp_str, temp_curr * pow(2, cursor), i + cursor);
								strncpy(temp_str, stream, strlen(stream));
							}
							//if (stream[i + cursor] == 'S')
							//	cursor = 0;
							if (cursor == 0)
								cursor = 1;
							swap(stream[i + cursor - 1], stream[i + pos]);
							hit_count += current_val * pow(2, cursor - 1);
							count += (pos - cursor + 1);
						} else
							current_val *= 2;
					} else {
						current_val *= 2;
					}
				}
			}

			if (hit_count > D)
				count = -1;
		} else if (always) {
			count = 0;
		} else if (impos) {
			count = -1;
		}
		
		cout << "Case #" << iter + 1 << ": ";
		if (count < 0)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << count << endl;

	}

	return 0;
}
