class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_set<char> st;
        int maxLen = INT_MIN;
        int left=0, right=0;

        while(right<n) {
            if(st.find(s[right]) == st.end()) {
                st.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
            else {
                st.erase(s[left]);
                left++;
            }
        }
        return (maxLen == INT_MIN) ? 0 : maxLen;
    }
};
