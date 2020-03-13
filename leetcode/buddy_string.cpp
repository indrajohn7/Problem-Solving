class Solution {
public:
    bool buddyStrings(string A, string B) {
        int arr[26] = {0};
        memset(arr, 0, 26 * sizeof(int));
        const char* str1 = A.c_str();
        const char* str2 = B.c_str();
        if (strlen(str1) != strlen(str2))
            return false;
        int len = strlen(str1);
        typedef pair<char, char> pcc;
        map<int, pcc> vmap;
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (str1[i] != str2[i]) {
                //vmap.insert(make_pair(i, make_pair(str1[i], str2[i])));
                vmap[i] = make_pair(str1[i], str2[i]);
            } else {
                arr[str1[i] - 'a']++;
            }
            
            //cout << i << " :: " << len << " :: " << count << endl;
            //cout << str1[i] << " :: " << str2[i] << endl;
            //cout << str1[i + 1] << " :: " << str2[i + 1] << endl;
            /*
            if ((count == 0) && (i < len - 1) && 
                    (str1[i] == str1[i + 1]) && (str2[i] == str2[i + 1]) &&
                    (str1[i] == str2[i])) {
                cout << "Positive";
                count++;
            }
            */
        }
        for(int i = 0; i < 26; i++) {
            if (arr[i] > 1) {
                count++;
                break;
            }
        }
        if (vmap.size() == 0 && count != 0)
            return true;
        if (vmap.size() == 2) {
            map<int, pcc> :: iterator it = vmap.begin();
            map<int, pcc> :: reverse_iterator it2 = vmap.rbegin();
            //cout << it->second.first << " :: " << it->second.second << endl;
            //cout << it2->second.first << " :: " << it2->second.second << endl;
            if (it->second.first == it2->second.second && 
                it->second.second == it2->second.first)
                return true;
        }
        
        return false;
    }
};
