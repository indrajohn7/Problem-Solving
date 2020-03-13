class ExamRoom {
public:
    int* arr;
    int num;
    set<int> sec;
    ExamRoom(int N) {
        num = N;
        arr = new int[N];
        memset(arr, 0, sizeof(int) * N);
    }
    
    int seat() {
        if (sec.size() == 0){
            sec.insert(0);
            return 0;
        } else if (sec.size() == 1) {
            set<int> :: iterator it = sec.begin();
            int res = 0;
            if (*it >= (num - *it)) {
                res = 0;
            } else {
                res = num - 1;
            }
            sec.insert(res);
            return (res);
        } 
        
        int max_gap, min_pos, zero_gap, end_gap;
        max_gap = min_pos = zero_gap = end_gap = 0;
        bool zero_flag, end_flag;
        zero_flag = end_flag = false;
        if (sec.find(0) == sec.end()) {
            zero_flag  = true;
            zero_gap = *(sec.begin());
        } 
        if (sec.find(num - 1) == sec.end()) {
            end_flag = true;
            end_gap = (num - 1) - (*(sec.rbegin()));
            cout << "end_gap: " << end_gap << endl;
        }
        if (zero_flag || end_flag) {
            if (end_gap > zero_gap) {
                zero_flag = false;
            } else if (end_gap <= zero_gap) {
                end_flag = false;
            } 
        }
        
        for (set<int> :: iterator it = sec.begin(); it != sec.end(); it++) {
            set<int> :: iterator iter = it;
            if (++iter == sec.end())
                break;
            if ((abs(*iter - *it) / 2) > max_gap) {
                max_gap = (abs(*iter - *it) / 2);
                min_pos = *it + max_gap;
            } else if ((abs(*iter - *it) / 2) == max_gap) {
                if (min_pos > (*it + max_gap)) {
                    min_pos = *it + max_gap;
                }
            }
            cout << "min_pos: " << min_pos << endl;
        }
        int res = min_pos;
        if (zero_flag) {
            if (zero_gap >= max_gap) {
                res = 0;
            } else {
                res = min_pos;
            }
        } else if (end_flag) {
            if (end_gap > max_gap) {
                res = num - 1;
            } else {
                res = min_pos;
            }
        }
        sec.insert(res);
        arr[res] = 1;
        return res;
    }
    
    void leave(int p) {
        arr[p] = 0;
        sec.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

