#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    ifstream fin;
    fin.open("data1.in");
    fin >> T;
    for (int t = 0; t < T; t++) {
        unsigned long long N, digit, temp;
        fin >> N;
        temp = N;
        digit = 0;
        deque<int> deq, res1, res2;
        while (temp) {
            
            deq.push_front(temp % 10);
            temp /= 10;
        }
        for (int i = 0; i < deq.size(); i++) {
            int first, second;
            if (((deq[i] / 2) == 4) || 
                (((deq[i] / 2) + 1) == 4)) {
                
                first = (deq[i] / 2) - 1;
                second = deq[i] - first;
            } else {
                first = deq[i] / 2;
                second = deq[i] - first;
            }
        	res1.push_back(first);    
        	res2.push_back(second);    
        }
		
		
        unsigned long long out1, out2;
        out1 = out2 = 0;
        for (int i = 0; i < res1.size(); i++) {
            out1 = (out1 * 10) + res1[i];
        }
        for (int i = 0; i < res2.size(); i++) {
            out2 = (out2 * 10) + res2[i];
        }
        
        cout << "Case #" << t + 1 << ": ";
        cout << out1 << " " << out2 << endl;
    }
    return 0;
}
