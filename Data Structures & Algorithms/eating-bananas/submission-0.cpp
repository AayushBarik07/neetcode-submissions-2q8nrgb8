class Solution {
public:
    // int findMax(vector<int> &piles) {
    //     int maxi=INT_MIN;
    //     for(int i=0;i<piles.size();i++) {
    //         maxi = max(maxi, piles[i]);
    //     }
    //     return maxi;
    // }
    long long totalTimeConsume(vector<int> &piles, int hrs) {
        long long totalHrs = 0;
        for(int i=0; i<piles.size(); i++) {
            totalHrs += (piles[i] + hrs - 1) / hrs;
        }
        return totalHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        
        while(low<=high) {
            int mid = (low + high) / 2;

            long long reqTime = totalTimeConsume(piles, mid);
            if(reqTime <= h) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};
