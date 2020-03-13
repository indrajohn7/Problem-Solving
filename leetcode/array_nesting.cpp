class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        map<int, int> vmap;
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            vmap[i] = nums[i];
            map<int, int> :: iterator it = vmap.begin();
            cout << it->first << " " << it->second << endl;
            int num = nums[i];
            while (1) {
                
                if (vmap.find(num) != vmap.end()) {
                    
                    break;
                } else {
                    vmap[num] = nums[num];
                }
               num = nums[num];
            }
            if (vmap.size() > max) {
                max = vmap.size();
            }
            cout << vmap.size() << endl;
            if (vmap.size() == nums.size())
                break;
            vmap.clear();
        }
        return max;
    }
};
