class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median;
        vector<int> ans;
        for(int i: nums1) ans.push_back(i);
        for(int i: nums2) ans.push_back(i);

        sort(ans.begin(), ans.end());

        if(ans.size() % 2 == 0) {
            return (ans[ans.size() / 2 - 1] + ans[ans.size() / 2])/2.0;
        }
        else return ans[ans.size() / 2];
    }
};
