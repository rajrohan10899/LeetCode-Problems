class Solution {
public:
// Optimal Approach -----> Time Complexity : O(n) ------>  Space Complexity : O(1).

    int numberOfSubstrings(string s) {
       int lastSeen[3] = {-1, -1, -1};
       int cnt = 0;
       for(int i = 0; i < s.length(); i++) {
            // Update the last seen index for the current character
            lastSeen[s[i] - 'a'] = i;
            // Check if all three characters have been seen
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                // Calculate the number of valid substrings ending at index i
                cnt  += (1 + min({lastSeen[0], lastSeen[1], lastSeen[2]}));
            }
       }
       return cnt;
    }
};
