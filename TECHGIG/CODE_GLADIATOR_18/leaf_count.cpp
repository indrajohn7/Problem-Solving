/* Read input from STDIN. Print your output to STDOUT*/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *a[])
{
    //Write code here
    int N, x;
    cin >> N;

	typedef pair <int, bool> pib;
	typedef vector <int> vi;
    map<int, pib> work;
	map<int, vi> parent;
    int count = 0;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        work[i] = make_pair(t, true);

		parent[t].push_back(i);
        map <int, pib> :: iterator it = work.begin();
        it = work.find(t);
        if (it != work.end() && it->second.second == true) {
            it->second.second = false;
            count++;
        } else if (it->second.second == false){
            work[t].second = false;
        } else {
			work[t].second = false;
			count++;
		}
    }
    int leaf_count = N - count;
    cin >> x;
    /*
	int layer = 1, depth =1;
    while (pow(2, layer) <= x)
        layer++;
    while (pow(2, depth) <= N)
        depth++;
    int rot = 0;
    while (rot != 2) {
    int iter = pow(2, (depth - layer - rot));
    int first = x * iter;
	
    for(int i = 0; i < iter; i++) {
        map <int, bool> :: iterator it = work.begin();
        it = work.find(first + i);
        if (it != work.end() && it->second == true){
            leaf_count--;
            it->second = false;  
        } else if (work.find(x) != work.end() && work[x] == true) {
            leaf_count--;
            work[x] = false;
        }
    }
    rot++;
    }
	*/

	list<int> queue;
	queue.push_back(x);

	
	while(queue.size() > 0) {

		int num = queue.front();
		map<int, pib> :: iterator iter = work.begin();
		iter = work.find(num);
		if (iter != work.end()) {
			if (iter->second.second == true) {
				iter->second.second = false;
				leaf_count--;
			}
		}

		map<int, vi> :: iterator it2 = parent.begin();
		it2 = parent.find(num);
		if (it2 != parent.end()) {
			for(int i = 0; i < it2->second.size(); i++) {
				queue.push_back(it2->second[i]);
			}
		}
		queue.pop_front();
	}
    cout << leaf_count;
    return 0;
}


