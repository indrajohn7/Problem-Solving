class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum = 0;
        
        multimap<int, int> mapout_A, mapout_B, mapin_A, mapin_B, gap_A, gap_B;
        int N = costs.size();
        for (int i = 0; i < costs.size(); i++) {
            int diff = abs(costs[i][0] - costs[i][1]);
            int A, B;
            A = costs[i][0];
            B = costs[i][1];
            
            if (costs[i][0] > costs[i][1]) {
                if (mapout_B.size() != N / 2) {
                    mapout_B.insert(make_pair(B, i));
                    gap_B.insert(make_pair(diff, i));
                    sum += B;
                } else {
                    if (gap_B.begin()->first < diff) {
                        int idx = gap_B.begin()->second;
                        int temp_A, temp_B;
                        temp_A = costs[idx][0];
                        temp_B = costs[idx][1];
                        mapout_B.erase(temp_B);
                        sum -= temp_B;
                        gap_B.erase(gap_B.begin()->first);
                        mapout_A.insert(make_pair(temp_A, idx));
                        gap_A.insert(make_pair(gap_B.begin()->first * (-1), idx));   //check this once
                        sum += temp_A;
                        mapout_B.insert(make_pair(B, i));
                        gap_B.insert(make_pair(diff, i));
                        sum += B;
                    } else {
                        mapout_A.insert(make_pair(A, i));
                        gap_A.insert(make_pair(diff, i));
                        sum += A;
                    }
                }
            } else if (costs[i][0] < costs[i][1]) {
                if (mapout_A.size() != N / 2) {
                    mapout_A.insert(make_pair(A, i));
                    gap_A.insert(make_pair(diff, i));
                    sum += A;
                } else {
                    if (gap_A.begin()->first < diff) {
                        int idx = gap_A.begin()->second;
                        int temp_A, temp_B;
                        temp_A = costs[idx][0];
                        temp_B = costs[idx][1];
                        mapout_A.erase(temp_A);
                        sum -= temp_A;
                        gap_A.erase(gap_A.begin()->first);
                        mapout_B.insert(make_pair(temp_B, idx));
                        gap_B.insert(make_pair(gap_A.begin()->first * (-1), idx));   //check this once
                        sum += temp_B;
                        mapout_A.insert(make_pair(A, i));
                        gap_A.insert(make_pair(diff, i));
                        sum += A;
                    } else {
                        mapout_B.insert(make_pair(B, i));
                        gap_B.insert(make_pair(diff, i));
                        sum += B;
                    }
                }
            } else {
                if (mapout_A.size() >= mapout_B.size()) {
                    mapout_B.insert(make_pair(B, i));
                    gap_B.insert(make_pair(diff, i));
                    sum += B;
                } else {
                    mapout_A.insert(make_pair(A, i));
                    gap_A.insert(make_pair(diff, i));
                    sum += A;
                }
            }
        }
        
        return sum;
    }
};
