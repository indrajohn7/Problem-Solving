class Solution {
public:
    bool buddyStrings(string A, string B) {
        char* str1 = A.c_str();
        char* str2 = B.c_str();
        if (strlen(str1) != strlen(str2))
            return false;
        int len = strlen(str1);
        typedef pair<char, char> pcc;
        map<int, pcc> vmap;
        int concurrent = 0;
        for (int i = 0; i < len; i++) {
            if (str1[i] != str2[i]) {
                vmap[i] = make_pair(str1[i], str2[i]);
            }
            if ((count == 0) && (i < len - 1) && 
                    (str1[i] == str1[i + 1] == str2[i] == str2[i + 1]))
                count++;
        }
        if (vmap.size() == 0 && count != 0)
            return true;
        if (vmap.size() == 2) {
            if (vmap[0].first == vmap[1].second && vmap[0].second == vmap[1].first)
                return true;
        }
        
        return false;
    }
};

