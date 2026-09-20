class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<int, int> mpp;
        for(int c: s) mpp[c]++;
        for(int c: t) mpp[c]--;

        for(auto &i: mpp) {
            if(i.second != 0) return false;
        }
        return true;
    }
};
