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

void combinationUtil2(vector<string> arr, vector<string>* data, vector<string>* final_data, int n, int r,  
                    int index, int i)  
{  
    // Current cobination is ready, print it  
    if (index == r)  
    {  
		string str;
        for (int j = 0; j < r; j++)  
        	str += (*data)[j];
		
		final_data->push_back(str);
		data->clear();
        return;  
    }  
  
    // When no more elements are there to put in data[]  
    if (i >= n)  
        return;  
  
    // current is included, put next at next location  
    data->push_back(arr[i]);  
    combinationUtil(arr, data, final_data, n, r, index + 1, i + 1);  
  
    // current is excluded, replace it with next (Note that  
    // i+1 is passed, but index is not changed)  
    combinationUtil(arr, data, final_data, n, r, index, i+1);  
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
		vecstr strdata;
        for (int i = 0; i < N; i++) {
            char* str = new char[100];
            memset(str, '\0', 100);
            fin >> str;
			strdata.push_back(str);
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
		vector<string> final_data;
		vector<string> init_data;
		init_data.push_back("a");
		init_data.push_back("e");
		init_data.push_back("i");
		init_data.push_back("o");
		init_data.push_back("u");
		
		
		for (int i = 1; i <= 5; i++) {
			vector<string> dummy;
			combinationUtil2(init_data, &dummy, &final_data, init_data.size(), i, 0, 0);
			dummy.clear();
		}

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

		vmap.clear();
		vowel_map.clear();
        cout << used.size() << endl;
    }
	fin.close();
    return 0;
}



