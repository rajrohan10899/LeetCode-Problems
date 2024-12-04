class Solution {
public:
    string minWindow(string s, string t) {
        int hashArr[256] = {0};  // Frequency map for characters in t
        for(char ch : t) 
            hashArr[ch]++; // Initialize with t's characters
        
        int i = 0, j = 0, count = 0;
        int startingIdx = -1, minWindow = INT_MAX;

        while(j < s.length()) {
            // Expand the window by including the current character
            hashArr[s[j]]--;

            // If the character is part of t and still needed
            if(hashArr[s[j]] >= 0) {
                count++;
            }
            // Try to shrink the window from the left
            while(count == t.length()) {
                // Update the minimum window size
                if(j - i + 1 < minWindow) {
                    minWindow = j - i + 1;
                    startingIdx = i;
                }
                // Shrink the window by removing the leftmost character
                hashArr[s[i]]++;
                if(hashArr[s[i]] > 0) {
                    count--;  // The character is no longer fully matched
                }
                i++;          // Move the left pointer forward
            }
            // Expand the window by moving the right pointer
            j++;
        }
        // If no valid window is found, return an empty string
        return (startingIdx == -1) ? "" : s.substr(startingIdx, minWindow);
    }
};
