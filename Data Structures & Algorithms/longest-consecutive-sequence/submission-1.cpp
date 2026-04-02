class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt=0, long_consecutive=0, last_smallest=INT_MIN;
        for(int i=0;i<n;i++) {
            if(nums[i] - 1 == last_smallest) {
                cnt++;
                last_smallest = nums[i];
            }
            else if(nums[i] != last_smallest) {
                cnt=1;
                last_smallest = nums[i];
            }
            long_consecutive = max(long_consecutive, cnt);
        }
        return long_consecutive;
    }
};
