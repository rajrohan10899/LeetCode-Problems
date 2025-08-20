class Solution {
public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int i = 0, j = 0, maxVowelCnt = 0, vowelCnt = 0;
        while (j < s.length()) {
            if (isVowel(s[j])) {
                vowelCnt++;
            }
            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {
                maxVowelCnt = max(maxVowelCnt, vowelCnt);

                if (isVowel(s[i])) {
                    vowelCnt--;
                }
                i++;
                j++;
            }
        }
        return maxVowelCnt;
    }
};