class Solution {
public:
    
    bool check_triangle_property(int a, int b, int c)
    {
        if (((a + b) > c) && ((b + c) > a) && ((a + c) > b))
            return true;
        return false;
    }
    
    int largestPerimeter(vector<int>& A) {
        if (A.size() < 3)
            return 0;
        
        int sum = 0;
        
        multiset<int> sec;
        bool ret = false;
        
        for (int i = 0; i < 3; i++) {
            
            sum += A[i]; 
            sec.insert(A[i]);
        }
         int first, second, last;
        /*
		int fst_idx, sec_idx, lst_idx;
        fst_idx = 0;
        sec_idx = rand() % A.size();
        lst_idx = A.size() - 1;
    
        for (int i = 0; i < A.size(); i++) {
            while(sec_idx != fst_idx && sec_idx != lst_idx) {
                sec_idx = rand() % A.size();
            }
            if (check_triangle_property(A[fst_idx], A[sec_idx], A[lst_idx])) {
                ret = true;
                first = A[fst_idx];
                second = A[sec_idx];
                last = A[lst_idx];
                sec.insert(first);
                sec.insert(second);
                sec.insert(last);
                break;
            }
            fst_idx++;
            lst_idx--;
            sec_idx = rand() % A.size();
        }
        */
        multiset<int> :: iterator it  = sec.begin();
       
        first = *it++;
        second = *it++;
        last = *it;
        if ((first + second) > last ) {
            ret= true;
        }
        
        for (int i = 3; i < A.size(); i++) {
            it = sec.begin();
            first = *it++;
            second = *it++;
            last = *it;
            bool first_length, second_length, last_length;
            first_length = second_length = last_length = false;
            
            if (ret) {
                if (((sum + A[i] - first) > sum) && 
                    check_triangle_property(second, last, A[i])) {
                        first_length = true;
                } else if (((sum + A[i] - second) > sum) && 
                    check_triangle_property(first, last, A[i])) {
                    second_length = true;
                } else if (((sum + A[i] - last) > sum) && 
                    check_triangle_property(first, second, A[i])) {
                    last_length = true;
                }
            } else {
                if (check_triangle_property(second, last, A[i])){
                    first_length = true;
                    ret = true;
                } else if (check_triangle_property(first, last, A[i])) {
                    second_length = true;
                    ret = true;
                } else if (check_triangle_property(first, second, A[i])) {
                    last_length = true;
                    ret = true;
                }
            }
            if (first_length){
                sum = sum + A[i] - first;
                sec.erase(first);
                sec.insert(A[i]);
            } else if (second_length) {
                sum = sum + A[i] - second;
                sec.erase(second);
                sec.insert(A[i]);
            }else if (last_length) {
                sum = sum + A[i] - last;
                sec.erase(last);
                sec.insert(A[i]);
            }
        }
        
        return (ret == false) ? 0 : sum;
    }
         
};

