#include<bits/stdc++.h>

using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
        //sort(people.begin(), people.end());
        multiset<int> sec;
        sec.insert(people.begin(), people.end());
        int pcount, count;
        pcount = count = 0;
        int sum = 0;
        int id1, id2;
        id1 = 0;
        id2 = people.size() - 1;
        for (multiset<int> :: reverse_iterator it = sec.rbegin(); 
            it != sec.rend(); it++){
            
            if (pcount < 2 && ((sum + *it) < limit)) {
                pcount++;
                sum += *it;
            } else if (pcount < 2 && ((sum + *it) == limit)) {
                count++;
                pcount = 0;
                sum = 0;
                
            } else if (pcount < 2 && ((sum + *it)> limit)) {
                int temp = limit - sum;
                int first = *(sec.begin());
                multiset<int> :: iterator it2 = sec.find(temp);
                while (temp >= first && it2 == sec.end()) {
                    --temp;
					it2 = sec.find(temp);
                }
                if (it2 != sec.end()) {
                    sec.erase(it2);    
                } 
                count++;
                pcount = 0;
                sum = 0;
				--it;
            }
            
            if (pcount == 2) {
                count++;
                sum = 0;
                pcount = 0;
            }
        }
        if (sum > 0) {
            count++;
        } 
        
        return count;
}

int main()
{
	ifstream fin;
	fin.open("boats.in");
	int T;
	fin >> T;
	for (int t = 0; t < T; t++) {
		int N, limit;
		fin >> N >> limit;
		vector<int> vec;
		for (int i = 0; i < N; i++) {
			int temp;
			fin >> temp;
			vec.push_back(temp);
		}
		int ret = numRescueBoats(vec, limit);
		cout << ret << endl;
	}
	return 0;
}
