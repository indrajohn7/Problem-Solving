/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <bits/stdc++.h>

using namespace std;

typedef multiset<int> sec;
typedef pair<int, int> pi;
typedef pair<pi, sec> pii;
typedef vector<pii> vpi;
typedef vector<sec> vsec;

/*Function to return max sum such that no two elements 
 are adjacent */
int FindMaxSum(int input[], int n) 
{ 
  	int incl = input[0]; 
  	int excl = 0; 
  	int excl_new; 
  	int i; 
	
	pii* arr = new pii[n + 1];
	multiset<int> v0, v1;
	arr[0] = make_pair(make_pair(0, 0), v0);
	v1.insert(incl);
	arr[1] = make_pair(make_pair(0, incl), v1);
	int max_val;
	map<int, vsec> vmap;
	int neg_count, zero_count, mini;
	neg_count = zero_count = 0;
	mini = -10000000;
	if (input[0] < 0) {
		neg_count++;
		if (input[0] > mini)
			mini = input[0];
	} else if (input[0] == 0) {
		zero_count++;
	}
	for (i = 1; i < n; i++) 
  	{ 

		if (input[i] < 0) {
			neg_count++;
			if (input[i] > mini)
				mini = input[i];
		} else if (input[i] == 0) {
			zero_count++;
		}
		
     /* current max excluding i */
	 /*	if (i == 1 && input[0] < 0 && input[1] < 0) {
			excl_new = incl;
		} else {*/
			excl_new = (incl > excl)? incl: excl; 
  	//	}
		/*
		if (incl > excl){
				arr[i]
		} else if (incl ==  excl) {
		
		} else {
		
		}
		*/
     /* current max including i */
	 	if ( !(input[i] < 0 && (excl + input[i]) < incl)) {
     		incl = excl + input[i];
		} 
     	
		excl = excl_new;
		
		multiset<int> s;
		int sum;
		if (input[i] > incl && input[i] > excl) {
			max_val = input[i];
			s.insert(input[i]);
			arr[i + 1] = make_pair(make_pair(i, input[i]), s);
			vmap[input[i]].push_back(s);
		} else if (incl > excl) {
			max_val = incl;
			s = arr[i - 1].second;
			s.insert(input[i]);
			arr[i + 1] = make_pair(make_pair(i, incl), s);
			vmap[incl].push_back(s); 
		} else if (incl == excl) {
			max_val = incl;
			s = arr[i - 1].second;
			if (input[i] != 0)
				s.insert(input[i]);
			arr[i + 1] = make_pair(make_pair(i, incl), s);
			vmap[incl].push_back(s); 
			
			s = arr[i].second;
			// insert is not required
			vmap[incl].push_back(arr[i].second); //not required 
		} else {
			arr[i + 1] = arr[i];
			max_val = excl;
			vmap[excl].push_back(arr[i].second); 
		}
  	}
	
	
	if ((neg_count + zero_count) == n) {
		if (zero_count != 0){
			cout << 0;
		} else {
			cout << mini;
		}
	} else {
	

		map<int, vsec> :: iterator it = vmap.find(max_val);
		vsec v = it->second;
		int maxi, idx;
		maxi = -9999999;
		for (int i = 0; i < it->second.size(); i++) {
			
			sec s = v[i];
			sec :: iterator iter = s.begin();
			//while((*iter) <= 0)
			//	iter++;
			if (*iter > maxi) {
					idx = i;
					maxi = *iter;
			}
		}
  	
		for (sec :: iterator iter = v[idx].begin(); iter != v[idx].end(); iter++) {
			//if (*iter > 0 ) {
				cout << *iter << " ";
		//	}
		}
	}
	cout << endl;
   /* return max of incl and excl */
	return ((incl > excl)? incl : excl); 
} 

int main(int argc, char *a[])
{
    //Write code here
	ifstream fin;
	fin.open("data2.in");
    int T;
    fin >> T;
    
	for (int t = 0; t < T; t++) {
        int N;
        fin >> N;
        int* input = new int[N];
        pii** arr = new pii*[N];
        for (int i = 0; i < N; i++) {
            int val;
            fin >> val;
            input[i] = val;
            arr[i] = new pii[N];
        }
		int ret = FindMaxSum(input, N);
		cout << ret << endl;
    }

    return 0;
}

