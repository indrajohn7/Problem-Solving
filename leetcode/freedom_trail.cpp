#include<bits/stdc++.h>

struct rotation {
    bool is_possible;
    int steps;
    dequeue<char> cdeq; 
    
    rotation(bool pos, int val, dequeue<char> dq)
    {
        is_possible = pos;
        steps = val;
        cdeq = dq;
    }
};

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        dequeue<char> deq;
        int count = 0;
        char* ring1 = ring.c_str();
        char* key1 = key.c_str();
        int len_ring, len_key;
        len_ring = strlen(ring1);
        len_key = strlen(key1);
        
        
        deq.insert(ring1, ring1 + len_string);
        
        rotation** rt = new rotation*[len_key1 + 1];
        for (int i = 0; i < (len_key1 + 1); i++){
            
            rt[i] = new rotation[len_ring1 + 1];
        }
        
        for (int i = 0; i < len_key1 + 1; i++) {
            for(int j = 0; j < len_ring1 + 1; j++) {
                if (i == 0 || j == 0) {
                    dequeue<char> DQ = deq;
                    rotation *rotat = new rotation(false, 0, DQ);
                    rt[i][j] = *rotat;
                } else {
                    int val;
                    dequeue<char> DQ;
                    if (rt[i - 1][j].is_possible && rt[i][j - 1].is_possible) {
                        if (rt[i - 1][j].steps < rt[i][j - 1].steps) {
                            val = rt[i - 1][j].steps;
                            DQ = rt[i - 1][j].cdeq;
                            
                            rotation* rotat = new rotation(true, val, DQ);
                        } else {
                            val = rt[i][j - 1].steps;
                            DQ = rt[i][j - 1].cdeq;
                            
                            rotation* rotat = new rotation(true, val, DQ);
                        }
                    } else if (rt[i - 1][j].is_possible) {
                        val = rt[i - 1][j].steps;
                        DQ = rt[i - 1][j].cdeq;
                            
                        rotation* rotat = new rotation(true, val, DQ);
                    } else if (rt[i][j - 1].is_possible) {
                        val = rt[i][j - 1].steps;
                        DQ = rt[i][j - 1].cdeq;
                            
                        rotation* rotat = new rotation(true, val, DQ);
                    } else {
                        val = rt[i][j - 1].steps;
                        DQ = rt[i][j - 1].cdeq;
                            
                        rotation* rotat = new rotation(false, val, DQ);
                    }
                    
                    if (key1[i] == ring1[j]) {
                        int forward_gap, backward_gap, val;
                        forward_gap = backward_gap = 0;
                        
						//Forward Propagation
                        dequeue<char> cdeq = rt[i][j].cdeq;
                        val = rt[i][j].steps;
                        
                        dequeue<char> :: iterator forward_iter = cdeq.begin();
                        forward_iter = find(cdeq.begin(), cdeq.end(), key1[i]);
                        for (dequeue<char> :: iterator iter = cdeq.begin(); 
                            iter != forward_iter; iter++) {
                            forward_gap++;
                        }
                
                        //backward Propagation
                        dequeue<char> :: reverse_iterator backward_iter = cdeq.rbegin();
                        backward_iter = find(cdeq.rbegin(), cdeq.rend(), key1[i]);
                        for (dequeue<char> :: reverse_iterator iter = cdeq.rbegin(); 
                            iter != backward_iter; ++iter) {
                            backward_gap++;
                        }
                        
                        if (forward_gap < backward_gap) {
                            char back = cdeq.back();
                            cdeq.pop_back();
                            cdeq.push_front(back);
                            val += forward_gap;
                        } else {
                            char front = cdeq.front();
                            cdeq.pop_front();
                            cdeq.push_back(front);
                            val += backward_gap;
                        }
                        rt[i][j].cdeq = cdeq;
                        rt[i][j].steps = val;
                        rt[i][j].is_possible = true;
                    } //if (ring1[j] == key[i]) ends
                } // else (i == 0 || j == 0) ends
            } // for j ends
        } // for i ends
        
        count = len_key1 + rt[len_key1][len_string1].steps;
        return count;
    }
};

