class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int low=0, high=n-1;

        while(low<=high) {
            if(!isalnum(s[low])) {
                low++;
                continue;
            }
            else if(!isalnum(s[high])) {
                high--;
                continue;
            }
            else if(tolower(s[low]) != tolower(s[high])) return false;
            else {
                low++;
                high--;
            }
        }
        return true;
    }
};
