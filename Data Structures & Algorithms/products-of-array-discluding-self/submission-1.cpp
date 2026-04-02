class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            int x = (i != 0) ? i-1 : -1;
            int y = (i != n-1) ? i+1 : n;
            int leftPro = 1, rightPro = 1;
            while(x>=0) {
                leftPro*=nums[x];
                x--;
            }
            while(y<n) {
                rightPro*=nums[y];
                y++;
            }
            ans[i] = leftPro*rightPro;
        } 
        return ans;
    }
};
