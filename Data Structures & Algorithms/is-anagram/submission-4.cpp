class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        // unordered_map<int, int> mp1;
        // unordered_map<int, int> mp2;
        // for(int i: s) mp1[i]++;
        // for(int i: t) mp2[i]++;
        // return mp1 == mp2;

        unordered_map<int, int> mp;
        for(int i: s) mp[i]++;
        for(int i: t) mp[i]--;
        
        for(auto &i: mp) {
            if(i.second != 0) return false;
        }
        return true;
    }
};
