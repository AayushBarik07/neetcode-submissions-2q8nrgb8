class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        unordered_map<char, int> freq;

        // Step 1: store freq of s1
        for(char c : s1) {
            freq[c]++;
        }

        int left = 0;

        // Step 2: sliding window
        for(int right = 0; right < s2.length(); right++) {

            // include current char
            freq[s2[right]]--;

            // maintain window size
            if(right - left + 1 > s1.length()) {
                freq[s2[left]]++;
                left++;
            }

            // check if all zero
            bool valid = true;
            for(const auto& it : freq) {
                if(it.second != 0) {
                    valid = false;
                    break;
                }
            }

            if(valid) return true;
        }

        return false;
    }
};
