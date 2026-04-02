class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxVol = INT_MIN;
        int left=0, right=n-1;
        while(left<right) {
            int vol = min(heights[left], heights[right]) * (right - left);
            maxVol = max(maxVol, vol);

            if(heights[left] < heights[right]) left++;
            else right--;
        }
        return maxVol;
    }
};
