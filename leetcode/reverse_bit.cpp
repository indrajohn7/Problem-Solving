#include<bits/stdc++.h>

using namespace std;

unsigned int reverseBits(unsigned int n) {
        unsigned int temp;
        temp = n;
        unsigned int res = 0;
        cout << n << endl;
        list<int> str;
        while (temp) {
            str.push_front(temp % 2);
            temp /= 2;
        }
        for (list<int> :: iterator it = str.begin(); it != str.end(); it++)
            cout << (*it);
       	cout << endl;

        while(str.size() != 32) {
            str.push_front(0);
        }
        int count = 31;
        for (list<int> :: reverse_iterator it = str.rbegin(); it != str.rend(); ++it) {
            int num = *it;
            res = res + (num * pow(2, count--));
        }
        
        return res;
}

int main()
{
	ifstream fin;
	fin.open("reverse.in");
	int N;
	fin >> N;
	 for(int i = 0; i < N; i++) {
	 	unsigned int num;
		fin >> num;
		unsigned int res = reverseBits(num);
		cout << res << endl;
	 }

	 return 0;
}

