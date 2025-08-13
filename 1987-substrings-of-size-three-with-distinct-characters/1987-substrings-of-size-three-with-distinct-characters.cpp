class Solution {
public:
    int countGoodSubstrings(string s) {

        int i = 0, j = 0, countGdSubstr = 0;
        unordered_map<char, int> mpp;

        while (j < s.length()) {
            mpp[s[j]]++;

            if (j - i + 1 < 3) {
                j++;
            } else {
                if (mpp.size() == 3) {
                    countGdSubstr++;
                }
                mpp[s[i]]--;
                if (mpp[s[i]] == 0) {
                    mpp.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return countGdSubstr;
    }
};