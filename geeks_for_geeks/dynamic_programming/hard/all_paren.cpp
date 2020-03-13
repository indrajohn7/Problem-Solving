#include<bits/stdc++.h>

using namespace std;

struct node {
	char* expr;
	int pos_start;
	int pos_end;
	int val;

	node(char* str, int p_s, int p_e, int v)
	{
		expr = new char[strlen(str)];
		strncpy(expr, str, strlen(str));
		pos_start = p_s;
		pos_end = p_e;
		val = v;
	}
};

int get_val(int first, char symbol, int last)
{
	switch(symbol){
		case '+': return (first + last);
		case '-': return (first - last);
		case '*': return (first * last);
		case '/': return (first / last);
		default:
			break;
	}

	return -1;
}

int get_all_combo(int* arr, char* brr, int len_int, int len_char)
{
	typedef vector<node*> vnd;
	vector<vnd> vec;
	vnd temp;
	
	int k = 0;
	for(int i = 0; i < (len_int - 1); i++) {
		char str[10];
		memset(str, '\0', sizeof(str));
		snprintf(str, sizeof(str), "(%d%c%d)", arr[i], brr[i], arr[i+1]);
		int val = get_val(arr[i], brr[i], arr[i+1]);
		node* nd = new node(str, i, i + 1, val);
		temp.push_back(nd);
	}
	
	vec.push_back(temp);

	int layer = 1, oper;
	oper = len_int;
	while(layer < (oper - 1)){
		temp.clear();
		int last = vec[vec.size()-1].size();
		for(int i = 0; i < last; i++){
			int start, end;
			start = vec[vec.size() - 1][i]->pos_start;
			int end_pos = vec[vec.size() - 1][i]->pos_end;
			end = start + strlen(vec[vec.size() - 1][i]->expr);
			
			if(start == 0 && end_pos == len_int - 1){
				temp.push_back(vec[vec.size() - 1][i]);
				continue;
			}

			if ((start - 1) >= 0){
				char str[50];
				memset(str, '\0', sizeof(str));
				snprintf(str, sizeof(str), "(%d%c%s)", arr[start - 1], brr[start - 1], vec[vec.size() - 1][i]->expr);
				int val = get_val(arr[start - 1], brr[start - 1], vec[vec.size() - 1][i]->val);
				node* nd = new node(str, start - 1, vec[vec.size() - 1][i]->pos_end, val);
				temp.push_back(nd);
			} 
			if((end_pos + 1) < len_int){
			
				char str[50];
				memset(str, '\0', sizeof(str));
				snprintf(str, sizeof(str), "(%s%c%d)", vec[vec.size() - 1][i]->expr, brr[end_pos], arr[end_pos + 1]);
				int val = get_val(vec[vec.size() - 1][i]->val, brr[end_pos], arr[end_pos + 1]);
				node* nd = new node(str, start, end_pos + 1, val);
				temp.push_back(nd);
			}
			if (i < (last - 2) && (vec[vec.size() - 1][i]->pos_end < vec[vec.size() - 1][i + 2]->pos_start)){
				 char str[50];
				 memset(str, '\0', sizeof(str));
				 snprintf(str, sizeof(str), "(%s%c%s)", vec[vec.size() - 1][i]->expr, brr[end_pos], vec[vec.size() - 1][i + 2]->expr);
				 int val = get_val(vec[vec.size() - 1][i]->val, brr[end_pos], vec[vec.size() - 1][i + 2]->val);
				 node* nd = new node(str, start, vec[vec.size() - 1][i + 2]->pos_end, val);
				 temp.push_back(nd);
			}
			
		}
		vec.push_back(temp);
		layer++;
	}

	int last = vec[vec.size()-1].size();
	for(int i = 0; i < last; i++){
		cout << vec[vec.size()-1][i]->expr << " :: " << vec[vec.size()-1][i]->val << endl;
	}

	return vec[vec.size()-1].size();
}


int main()
{
	int num_test;
	ifstream fin;
	fin.open("paren.in");
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++){
	
		int arr[100];
		char brr[100];
		int len_int = 0, len_char = 0;
		while(fin.good()) {
			fin >> arr[len_int++];
			fin >> brr[len_char++];
		}
		--len_char;
		cout << "Case #" << iter + 1 << ": " ;
		int res = get_all_combo(arr, brr, len_int, len_char);

	}

	return 0;
}
