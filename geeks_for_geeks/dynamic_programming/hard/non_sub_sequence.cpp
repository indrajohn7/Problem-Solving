#include<bits/stdc++.h>

using namespace std;

map<int, bool> vmap;

typedef vector<int> vi;
typedef pair<int,vi> pvi;

void get_min_subseq(int* arr, int N)
{
	pvi vec[N];
	
	for(int i = 0; i < N; i++)
		vec[i].first = 1;

	vec[0].second.push_back(0);
	int max = 0, idx = 0;
	for(int i = 1; i < N; i++){
		for(int j = 0; j < i; j++){
			if(arr[j] < arr[i] && ((vec[j].first + 1) > vec[i].first)){
				vec[i].first = vec[j].first + 1;
				vec[i].second = vec[j].second;
			}
		}
		vec[i].second.push_back(i);
		if(vec[i].second.size() > max){
			max = vec[i].second.size();
			idx = i;
		}
	}
	
	cout << "MIN SEQ: ";
	for(int i = 0; i < vec[idx].second.size(); i++){
		cout << arr[vec[idx].second[i]] << " ";
		vmap[vec[idx].second[i]] = true;
	}
	cout<< endl;

}



void get_max_subseq(int* arr, int N)
{
	pvi vec[N];
	
	for(int i = 0; i < N; i++)
		vec[i].first = 1;

	vec[0].second.push_back(0);
	int max, idx;
	max = idx = 0;
	for(int i = 1; i < N; i++){
		for(int j = 0; j < i; j++){
			if(arr[j] > arr[i] && ((vec[j].first + 1) > vec[i].first)){
				vec[i].first = vec[j].first + 1;
				vec[i].second = vec[j].second;
			}
		}
		vec[i].second.push_back(i);
		if(vec[i].second.size() > max){
			max = vec[i].second.size();
			idx = i;
		}
	}
	
	cout << "MAX SEQ: ";
	for(int i = 0; i < vec[idx].second.size(); i++){
		cout << arr[vec[idx].second[i]] << " ";
		vmap[vec[idx].second[i]] = true;
	}
	cout << endl;
}

int main()
{
	int num_test;
	ifstream fin;
	fin.open("sub_seq.in");
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++){
		int N;
		fin >> N;
		int* arr = new int[N];
		for(int i = 0; i < N; i++)
			fin >> arr[i];
		get_min_subseq(arr, N);
		get_max_subseq(arr, N);

		vector<int> vec;
		for(int i = 0; i < N; i++){
			map<int, bool>::iterator it = vmap.begin();
			if(vmap.find(i) == vmap.end())
				vec.push_back(arr[i]);
		}

		cout << "Case #" << iter + 1 << ": ";
		for(int i = 0; i < vec.size(); i++)
			cout << vec[i] << " ";
		cout << endl;
	}

	return 0;

}
