class Solution {
public:
    string multiply(string num1, string num2) {
        int carry = 0;
        string greater, lesser;
        if (num1.length() > num2.length()) {
            greater = num1;
            lesser = num2;
        } else {
            greater = num2;
            lesser = num1;
        }
        int count = 0;
        list<list<int>> vlist;
        
        for (string :: reverse_iterator it1 = lesser.rbegin(); 
            it1 != lesser.rend(); it1++) {
            carry = 0;
            list<int> alist;
            for (int i = 0; i < count; i++) {
                    alist.push_front(0);
            }
            val1 = (int)(*it1 - '0');
            for (string :: reverse_iterator it2 = greater.rbegin();
                it2 != greater.rend(); it2++) {
                
                int val1, val2. remain;
                
                val2 = (int)(*it2 - '0');
                remain = ((val1 * val2) + carry) % 10;
                carry = ((val1 * val2) + carry) / 10;
                alist.push_front(remain);
                
            }
            while (carry) {
                alist.push_front(carry % 10);
                carr /= 10;
            }
            vlist.push_back(alist);
            alist.remove();
            count++;
        }
    }
    
    for (list :: iterator it1 = vlist.begin; it1 != vlist.end(); it1++) {
        list<int> alist = *it1;
        
    }
};
