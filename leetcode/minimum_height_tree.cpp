#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<int> findMinHeightTrees(int n, vector<vi>& edges) {

        map<int, vi> vmap;
        for (int i = 0; i < n; i++) {
            int first, second;
            first = edges[i][0];
            second = edges[i][1];
            if (vmap.find(first) == vmap.end()) {
                vector<int> v;
                v.push_back(second);
                vmap[first] = v;
            } else {
                vmap[first].push_back(second);
            }
            if (vmap.find(second) == vmap.end()) {
                vector<int> v;
                v.push_back(first);
                vmap[second] = v;
            } else {
                vmap[second].push_back(first);
            }
        }
        vector<int> vec;
        int count = n + 1;
        for (map<int, vi> :: iterator it = vmap.begin();
            it != vmap.end(); ++it) {
            int node = it->first;
           // vector<int> v = it->second;
            int depth, temp_depth;
            depth = temp_depth = 0;
            stack<int> s;
            s.push(node);
            vector<int> visited;
            visited.push_back(node);
			
			map<int, int> gmap;
			gmap[node] = 0;
            while(s.size() != 0) {
                int temp_node = s.top();
                map<int, vi> :: iterator it2 = 
                    vmap.find(temp_node);
                
                vector<int> temp_v = it2->second;
                bool flag = false;
				int idx = 0;

				if (gmap.find(temp_node) != gmap.end()) {
					idx = gmap[temp_node];
				} else {
					gmap[temp_node] = 0;
				}
                for (int i = idx; i < temp_v.size(); i++) {
                    vector<int> :: iterator it3 = visited.begin();
                    it3 = find(visited.begin(), visited.end(), temp_v[i]);
                    if (it3 == visited.end()) {
                        s.push(temp_v[i]);
                        visited.push_back(temp_v[i]);
						gmap[temp_node] = i;
                        flag = true;
                        break;
                    }
                }
                if (flag == false) {
                    temp_depth = s.size() - 1;
                    s.pop();
                }
                if (temp_depth > depth) {
                    depth = temp_depth;
                }
            }
            if (depth < count) {
                vec.clear();
                vec.push_back(node);
				count = depth;
            } else if (depth == count) {
                vec.push_back(node);
            }
        }
        
        return vec;
    }

int main()
{
	int T;
	ifstream fin;
	fin.open("mht.in");
	fin >> T;
	for (int t = 0; t < T; t++) {
		
		int N;
		fin >> N;	
		vector <vi> vec;
		for (int i = 0; i < N; i++) {
			vi v;
			int first, second;
			fin >> first >> second;
			v.push_back(first);
			v.push_back(second);
			vec.push_back(v);
		}
		vi res = findMinHeightTrees(N, vec);
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << "\t";
		}
		cout << endl;
	}
	
	return 0;
}
