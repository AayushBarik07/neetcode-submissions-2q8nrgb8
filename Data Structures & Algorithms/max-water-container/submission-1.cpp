class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxVol = INT_MIN;
        int l=0, r=n-1;

        while(l<r) {
            int vol = min(heights[l], heights[r]) * (r - l);
            maxVol = max(maxVol, vol);

            if(heights[l] < heights[r]) l++;
            else r--;
        }
        return maxVol;
    }
};
