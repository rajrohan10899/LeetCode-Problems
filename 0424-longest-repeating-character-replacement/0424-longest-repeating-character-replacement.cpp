class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0, maxLen = 0, maxfreqCh = 0;
        int seen[26] = {0}; // Frequency array for characters 'A' to 'Z'

        while (j < s.length()) {
            seen[s[j] - 'A']++; // Increment frequency of current character
            maxfreqCh = max(maxfreqCh, seen[s[j] - 'A']); // Update max frequency
            
            // Trim down the window if it becomes invalid
            while ((j - i + 1) - maxfreqCh > k) {
                seen[s[i] - 'A']--; // Decrease frequency of leftmost character
                i++;                // Move the left pointer
            }
            // Update maxLen with the current valid window size
            maxLen = max(maxLen, j - i + 1);
            j++; // Move the right pointer
        }
        return maxLen;
    }
};
