class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";

        int l=0, r=0, minLen = INT_MAX, cnt=0, startIndex = -1;
        int hash[256] = {0};    

        for(int i=0;i<t.length();i++) {
            hash[t[i]]++;
        }    

        while(r < s.length()) {
            if(hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;   

            while(cnt == t.length()) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }

                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};
