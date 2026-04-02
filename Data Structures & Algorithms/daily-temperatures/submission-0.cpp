class Solution {
public:
    int nextGreaterIdxFunc(vector<int>& temperatures, int idx, int num) {
        for(int i=idx;i<temperatures.size();i++) {
            if(temperatures[i] > num) return i;
        }
        return 0;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans;
        for(int i=0;i<n;i++) {
            int nextGreaterIdx = nextGreaterIdxFunc(temperatures, i, temperatures[i]);
            if(nextGreaterIdx > 0)ans.push_back(nextGreaterIdx - i);
            else ans.push_back(0);
        }
        return ans;
    }
};
