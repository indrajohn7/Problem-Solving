/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<bits/stdc++.h>
#define VOWELS 5

using namespace std;

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

multimap<int, char> vowel_map;

unsigned long get_number_of_ways(int N) 
{
    if (N <= 0)
        return 0;
    unsigned long res = ((N * (N - 1) * (N - 2)) / 6);
    return res;
}

void combinationUtil(vector<string> arr, vector<string>* data, vector<string>* final_data,
                    int start, int end,  
                    int index, int r)  
{  
    // Current combination is ready 
    // to be printed, print it  
    if (index == r)  
    {  
		string str;
        for (int j = 0; j < r; j++)  
        	str += (*data)[j];
		
		final_data->push_back(str);
		data->clear();
        return;  
    }  
  
    // replace index with all possible  
    // elements. The condition "end-i+1 >= r-index" 
    // makes sure that including one element  
    // at index will make a combination with  
    // remaining elements at remaining positions  
    for (int i = start; i <= end &&  
        end - i + 1 >= r - index; i++)  
    { 	
		data->push_back(arr[i]);
        combinationUtil(arr, data, final_data, i+1,  
                        end, index+1, r);  
    }  
}  

int main()
{
    ifstream fin;
	fin.open("mask.in");
	int T;
    fin >> T;
   // populate_vowel_map();
    for (int i = 0; i < T; i++) {
        int N;
        fin >> N;
    	int arr[5] = {0};
		memset(arr, 0, 5 * sizeof(int));
        typedef vector<string> vecstr;
        map<char, vecstr> vmap;
        for (int i = 0; i < N; i++) {
            char* str = new char[100];
            memset(str, '\0', 100);
            fin >> str;
            for(int i = 0; i < VOWELS; i++) {
                if (strchr(str, vowels[i]) != NULL) {
                    string str1(str);
                    vmap[vowels[i]].push_back(str1);
                    arr[i] += 1;
                }
                    
            }
        }
        map<string, int> used;
        for (int i = 0; i < 5; i++){
            vowel_map.insert(make_pair(arr[i],vowels[i]));
        }
        unsigned long res = 0;
		for (map<char, vecstr> :: iterator it = vmap.begin(); it != vmap.end(); it++) {
			
			vector<string> final_data;
			vector<string> dummy;
			combinationUtil(it->second, &dummy, &final_data, 0, it->second.size() - 1, 0, 3);
			for (int i = 0; i < final_data.size(); i++){
				if (used.find(final_data[i]) == used.end())
					used[final_data[i]] = 1;
			}
			final_data.clear();
			dummy.clear();
		}
        /*
        for (map<char, vecstr> :: iterator it = vmap.begin(); it != vmap.end(); it++) {
            int len = it->second.size();
            res += get_number_of_ways(len);
        }
        
        for (int i = 0; i < 5; i++) {
            if (i != 0)
            res += get_number_of_ways(arr[i]);
        }
        
        vector<char> cvec;
        for (map<int, char> :: reverse_iterator it = vowel_map.rbegin(); it != vowel_map.rend(); ++it) {
            int count = it->first;
            
            if (it != vowel_map.rbegin()) {
                for (int i = 0; i < cvec.size(); i++) {
                    char c = cvec[i];
                    map<char, vecstr> :: iterator iter = vmap.find(c);
                    if (iter != vmap.end()){
                        for (int j = 0; j < iter->second.size(); j++){
                            if (strchr(iter->second[j].c_str(), c) != NULL){
                                count--;
                            }
                        }
                    }
                }
            }	
        }
        */

		vmap.clear();
		vowel_map.clear();
        cout << used.size() << endl;
    }
	fin.close();
    return 0;
}


