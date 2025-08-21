class Solution {
public:
    int characterReplacement(string s, int k) {

        int i = 0, j = 0, maxLen = 0, maxCharFreq = 0, hashArr[26] = {0};

        while(j < s.length()) {
            hashArr[s[j] - 'A']++;

            maxCharFreq = max(maxCharFreq, hashArr[s[j] - 'A']);
            int replacementReq = (j-i+1) - maxCharFreq;

            if(replacementReq <= k) {
                maxLen = max(maxLen, j-i+1);
            }
            else if(replacementReq > k) {
                while((j-i+1) - maxCharFreq > k) {
                    hashArr[s[i] - 'A']--;
                    i++;
                }
                maxLen = max(maxLen, j-i+1);   
            }
            j++;
        }
        return maxLen;
    }
};