class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        unordered_map<char, int> mpp;
        int maxlenSubstr = 0;

        while (j < s.length()) {
            // calculation: insert in map
            mpp[s[j]]++;

            // conditiom check 1.
            // if (mpp.size() < k) {
            //     j++;
            // }
            // 2
            if (mpp.size() == j - i + 1) {
                // ans nikalo calculaation se
                maxlenSubstr = max(maxlenSubstr, j - i + 1);
                j++;
            }
            // 3
            else if (mpp.size() < j - i + 1) {
                while (mpp.size() < j - i + 1) {
                    // calculation se remove i
                    mpp[s[i]]--;
                    if (mpp[s[i]] == 0) {
                        mpp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxlenSubstr;
    }
};