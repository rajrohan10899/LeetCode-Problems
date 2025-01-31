class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        for(int i = 0; i < s.length(); i++) {
            vector<char> seen(256, 0);
            for(int j = i; j < s.length(); j++) {
                if(seen[s[j]] == 1) 
                    break;
                maxlen = max(maxlen, j-i+1);
                seen[s[j]] = 1;

            }
        }
        return maxlen;
    }
};