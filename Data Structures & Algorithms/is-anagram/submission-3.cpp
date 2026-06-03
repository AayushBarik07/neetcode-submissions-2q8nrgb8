class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        if(s.length() != t.length()) return false;
        for(int i: s) mp1[i]++;
        for(int i: t) mp2[i]++;
        return mp1 == mp2;
    }
};
