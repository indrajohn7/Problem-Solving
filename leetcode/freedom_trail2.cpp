#include<bits/stdc++.h>
//#include<dequeue.h>
using namespace std;

struct rotation {
    public:
    bool is_possible;
    int steps;
    deque<char> cdeq; 
    
    rotation(bool pos, int val, deque<char> dq)
    {
        is_possible = pos;
        steps = val;
        cdeq = dq;
		/*
		memset(cdeq, '\0', strlen(dq));
		strncpy(cdeq, dq, strlen(dq));
		*/
    }
};


int findRotateSteps(string ring, string key)
{
	typedef vector<rotation*> vrec;
	multimap <char, vrec> vmap;
	int len_ring = ring.length();
	int len_key = key.length();
	const char* ring1 = ring.c_str();
	const char* key1 = key.c_str();
	
	vrec current, temp;
	int out = 99999;
	for (int i = 0; i < len_key; i++) {
		char c = key1[i];
		char* pos;
		deque<char> temp_ring;
		if (i == 0) {
			deque<char> cdeq;
			cdeq.assign(ring1, ring1 + len_ring);
			for (int idx = 0; idx < len_ring; idx++) {
				
				if (c == cdeq[idx]) {
					deque<char> deq;
					deq = cdeq;
					int forward, backward;
					forward = idx;
					backward = len_ring - idx;
					int mini = min(forward, backward);
					if (forward <= backward) {
						for (int p = 0; p < forward; p++) {
							char front = deq.front();
							deq.pop_front();
							deq.push_back(front);
						}
					} else {
						for (int p = 0; p < backward; p++) {
							char back = deq.back();
							deq.pop_back();
							deq.push_front(back);
						}
						
					}
					int steps = mini;
					
					rotation* rotat = new rotation(true, steps, deq);
					current.push_back(rotat);
				}
			}
		}
		for (int j = 0; j < temp.size(); j++){
			temp_ring = temp[j]->cdeq;
			for(int idx = 0; idx < temp_ring.size(); idx++) {
				if (c == temp_ring[idx]) {
					deque<char> deq;
					deq = temp_ring;
					int forward, backward;
					forward = idx;
					backward = len_ring - idx;
					int mini = min(forward, backward);
					if (forward <= backward) {
						for (int p = 0; p < forward; p++) {
							char front = deq.front();
							deq.pop_front();
							deq.push_back(front);
						}
					} else {
						for (int p = 0; p < backward; p++) {
							char back = deq.back();
							deq.pop_back();
							deq.push_front(back);
						}
						
					}
					int steps = mini + temp[j]->steps;
					
					rotation* rotat = new rotation(true, steps, deq);
					current.push_back(rotat);
				}
			}
			
			temp_ring.clear();
		}
		for(int i = 0; i < temp.size(); i++) {
			if (temp[i] != NULL)
				delete(temp[i]);
		}
		temp.clear();
		temp = current;
		current.clear();
	}

	for (int i = 0; i < temp.size(); i++) {
		if (out > temp[i]->steps) {
			out = temp[i]->steps;
		}
	}

	return (out + len_key);
}

int main() {
    string line;
	ifstream fin;
	fin.open("freedom.in");
	int T;
	fin >> T;

    for(int i = 0; i < T; i++) {
		
        string ring, key;
       	fin >> ring;
		fin >> key;
        int ret = findRotateSteps(ring, key);

        //string out = to_string(ret);
        cout << ret << endl;
    }
    return 0;
}
