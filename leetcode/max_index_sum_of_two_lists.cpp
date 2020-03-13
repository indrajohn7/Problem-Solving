class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> vec;
        map<string, int> vmap1, vmap2;
        for (int i = 0; i < list1.size(); i++){
            if (list1.size() <= list2.size())
                vmap1[list1[i]] = i;
            else
                vmap2[list1[i]] = i;
        }
        for (int i = 0; i < list2.size(); i++){
            if (list1.size() <= list2.size())
                vmap2[list2[i]] = i;
            else
                vmap1[list2[i]] = i;
        }
        int mini = list1.size() + list2.size();
        for (map<string, int> :: iterator it1 = vmap1.begin(); it1 != vmap1.end(); it1++) {
            map<string, int> :: iterator it2 = vmap2.begin();
            string name = it1->first;
            int pos1, pos2;
            it2 = vmap2.find(name);
            if (it2 != vmap2.end()) {
                pos1 = it1->second;
                pos2 = it2->second;
                if (pos1 + pos2 < mini) {
                    mini = pos1 + pos2;
                    vec.clear();
                    vec.push_back(name);
                } else if (pos1 + pos2 == mini) {
                    vec.push_back(name);
                }
            }
        }
        return vec;
    }
};
