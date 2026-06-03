class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        for(int i=0; i<n; i++) {
            if(seen.find(nums[i]) == seen.end()) {
                seen.insert(nums[i]);
            }
            else return true;
        }
        return false;

        /*
        unordered_map<int, int> freq;
        for(int i: nums) freq[i]++;

        for(auto it: freq) {
            if(it.second > 1) return true;
        }
        return false;
        */

        // sort(nums.begin(), nums.end());
        // for(int i=1;i<nums.size();i++) {
        //     if(nums[i] == nums[i-1]) return true;
        // } 
        // return false;
    }
};