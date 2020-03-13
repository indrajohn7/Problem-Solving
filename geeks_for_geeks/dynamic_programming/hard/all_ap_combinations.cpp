#include<bits/stdc++.h>

using namespace std;


typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef pair<int,vpi> pii;
typedef map<int,vpi> vmap;


int sum(int N)
{
	if(N == 0)
		return 0;
	else
		return (N + sum(N - 1));
}

int max_freq(vmap work)
{
	int max = 0;
	for(vmap::iterator it = work.begin(); it != work.end(); it++){
		for(int i = 0; i < it->second.size(); i++){
			max += sum((it->second[i].second - it->second[i].first) / it->first);	
		}
	}
	return max;
}

int get_all_ap_combinations(int* set, int N)
{
	int max = 1;
	sort(set, set+N);
	vmap work;
	for(int i=1;i<N;i++){
		for(int j=0;j<i;j++){
			int diff = set[i] - set[j];
			vmap::iterator it = work.begin();
			it = work.find(diff);
			if(it == work.end()){
				work[diff].push_back(make_pair(set[j],set[i]));
			} else {
				bool  flag = false;
				for(int k = 0; k < it->second.size(); k++){
					//work[diff].push_back(make_pair(set[j],set[i]));
					//it->second.second = set[i];
					if(it->second[k].second == set[j]){
						it->second[k].second = set[i];
						flag = true;
						break;
					}
				}
				if(!flag){
					work[diff].push_back(make_pair(set[j],set[i]));
				}
			}
		}
	}
	int res = (N + 1) + max_freq(work);
	return res;
}

/*
int get_all_ap_combinations(int* arr, int N)
{
	
}
*/
int main()
{
	int num_test;
	ifstream fin;
	fin.open("ap.in");
	fin >> num_test;
	for(int iter = 0; iter < num_test; iter++){
		int N;
		fin >> N;
		int* arr = new int[N];
		for(int i = 0; i < N; i++)
			fin >> arr[i];

		int res = get_all_ap_combinations(arr, N);
		cout << "Case #" << iter + 1 << ": " << res << endl;
	}

	return 0;
}
