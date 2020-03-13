#include<bits/stdc++.h>

using namespace std;


int get_hit_count(int* arr, int N, int fn)
{
	typedef vector<int> vi;
	map<int, vi> holder;
	map<int, bool> work;
	int hit = 0;

	for(int i = 0; i < N; i++){
		if(holder.find(arr[i]) != holder.end())
			holder.find(arr[i])->second.push_back(i);
		else{
			vector<int> v;
			v.push_back(i);
			holder[arr[i]] = v;
		}
	}

	for(int i = 0; i < N; i++){
		if(work.size() <= fn && work.find(arr[i]) != work.end())
			hit++;
		else{
			if(work.size() < fn){
				work[arr[i]] = true;
			} else {
				int dist = i, temp;
				temp = work.begin()->first;
				for(map<int, bool>::iterator it = work.begin(); it != work.end(); it++){
					int val = it->first;
					map<int, vi>:: iterator it2 = holder.find(val);
					for(int j = 0; j < it2->second.size(); j++){
						if(it2->second[j] > i && it2->second[j] > dist){
							dist = it2->second[j];
							temp = val;
							break;
						} else if (it2->second[j] > i) {
							break;
						} else if (j == it2->second.size() - 1) {
							
							dist = it2->second[j];
							temp = val;
						}
					}
				}
				work.erase(work.find(temp));
				work[arr[i]] = true;
			}
		}
	}

	return hit;
}


int main()
{
	int num_test;
	ifstream fin;
	fin.open("page.in");
	fin >> num_test;
	cout << "Case #	" << "Hit\t"<< "Miss" << endl;
	for(int iter = 0; iter < num_test; iter++){
		int N, frames;
		fin >> N >> frames;
		int* arr = new int[N];
		for(int i = 0; i < N; i++)
			fin >> arr[i];
		
		int hit, miss;
		hit = get_hit_count(arr, N, frames);
		miss = N - hit;

		cout << iter + 1 << "\t" << hit << "\t" << miss << endl;
	}
	return 0;
}
