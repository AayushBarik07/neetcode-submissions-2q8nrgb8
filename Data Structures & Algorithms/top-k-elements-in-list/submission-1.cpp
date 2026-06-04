class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> freq;

        for(int i=0; i<n; i++) {
            freq[nums[i]]++;
        }   

        vector<pair<int, int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second;
        });

        vector<int> ans;
        for(int i=0;i<k;i++) {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
