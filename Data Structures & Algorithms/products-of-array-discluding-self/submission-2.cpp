class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // Optimal Appr.
        vector<int> ans(n);
        ans[0] = 1;
        for(int i=1;i<n;i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }
        int suffix = 1;

        for(int i=n-1;i>=0;i--) {
            ans[i] = ans[i]*suffix;
            suffix*=nums[i];
        }
        return ans;


        // T.C - O(n2) ; S.C - O(n)
        // vector<int> ans(n);
        // for(int i=0;i<n;i++) {
        //     int x = (i != 0) ? i-1 : -1;
        //     int y = (i != n-1) ? i+1 : n;
        //     int leftPro = 1, rightPro = 1;
        //     while(x>=0) {
        //         leftPro*=nums[x];
        //         x--;
        //     }
        //     while(y<n) {
        //         rightPro*=nums[y];
        //         y++;
        //     }
        //     ans[i] = leftPro*rightPro;
        // } 
        // return ans;
    }
};
