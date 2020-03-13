#include<bits/stdc++.h>

using namespace std;

long maximumPeople(vector<long> p, vector<long> x, vector<long> y, vector<long> r) {
    // Return the maximum number of people that will be in a sunny town after removing exactly one cloud.
    
    unsigned long long max_people = 0;
	
	multimap<long long, unsigned long long> vmap;
    for (int i = 0; i < y.size(); i++) {
        long locate = y[i];
        long range = r[i];

		vmap.insert(make_pair((locate - range), (locate + range)));
    }

    unsigned long long maxi ,count;
	maxi = count = 0;
	map<long, long> cloud;
	typedef vector<long> vlong;
	multimap<unsigned long long, vlong> city;
	for (map<long long, unsigned long long> :: iterator it = vmap.begin(); it != vmap.end(); it++) {
		unsigned long long sum = 0;
		vector<long> vec;
		for (int i = 0; i < x.size(); i++) {
			if (x[i] >= it->first && x[i] <= it->second) {
				sum += p[i];
				if (cloud.find(x[i]) == cloud.end()) {
					cloud[x[i]] = 1;
				} else {
					cloud[x[i]] += 1;
				}
				vec.push_back(x[i]);
			} else if (x[i] > it->second) {
				break;
			}
		}
		city.insert(make_pair(sum, vec));
		vec.clear();
		/*
		if (sum > maxi) {
			maxi = sum;
		}
		*/
	}
	for (multimap<unsigned long long, vlong> :: reverse_iterator it = city.rbegin();
			it != city.rend(); it++) {
		bool flag = true;
		for (int i = 0; i < it->second.size(); i++) {
			int locate = it->second[i];
			if (cloud.find(locate)->second != 1) {
				flag = false;
				break;
			}
		}
		if (flag) {
			maxi = it->first;
			break;
		}
	}
    for (int i = 0; i < x.size(); i++) {
        long locate = x[i];
		count = 0;
		for (map<long long, unsigned long long> :: iterator it = vmap.begin(); it != vmap.end(); it++) {
			if (it->first > locate || (count > 1))
				break;
			if (locate >= it->first && locate <= it->second) {
				count++;
			}
		}
		if (count == 0) {
			max_people += p[i];
		} else if (count == 1) {
			if (p[i] > maxi) {
				maxi = p[i];
			}
		}
    }

    max_people += maxi;

    return max_people;

}

int main()
{
	ifstream fin;
	fin.open("cloud.in");
	int T;
	fin >> T;
	for (int t = 0; t < T; t++) {
		int N, K;
		fin >> N;
		vector<long> pop, loc, clo, ran;
		for (int i = 0; i < N; i++) {
			long temp;
			fin >> temp;
			pop.push_back(temp);
		}
		for (int i = 0; i < N; i++) {
			long temp;
			fin >> temp;
			loc.push_back(temp);
		}
		fin >> K;

		for (int i = 0; i < K; i++) {
			long temp;
			fin >> temp;
			clo.push_back(temp);
		}
		for (int i = 0; i < K; i++) {
			long temp;
			fin >> temp;
			ran.push_back(temp);
		}

		long res = maximumPeople(pop, loc, clo, ran);

		cout << res << endl;
	}

	return 0;
}

