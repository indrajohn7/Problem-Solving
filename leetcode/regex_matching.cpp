class Solution {
public:
    bool isMatch(string s, string p) {
    vector<vector<int>> d(s.size()+1, vector<int>(p.size()+1, -1)); //-1:yet, 0:false, 1:true
    return match(0, 0, s, p, d);
}


bool match(int i, int k, string& s, string& p, vector<vector<int>>& d) {
    
    if (i < s.size() && k < p.size() && d[i][k] !=-1) {
        return d[i][k];
    }
    
    if (k==p.size()) {
        return i == s.size();
    }
    
    bool firstMatch = i < s.size() && (p[k] == s[i] || p[k] == '.');
    
    bool m = false;
    if (k+1 < p.size() && p[k+1] =='*') {
        m = match(i, k+2, s, p, d) || (firstMatch && match(i+1, k, s, p, d));
    } else {
        m = firstMatch && match(i+1, k+1, s, p, d);
    }
    return d[i][k] = m ? 1 : 0;
}    
};
