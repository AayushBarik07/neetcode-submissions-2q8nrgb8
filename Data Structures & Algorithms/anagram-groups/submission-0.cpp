class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        map<string, vector<string>> store;

        for(string str: strs) {
            string s = str;
            sort(s.begin(), s.end());
            store[s].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto it=store.begin(); it!=store.end();it++) {
            ans.push_back(it-> second);
        }
        return ans;
    }
};
