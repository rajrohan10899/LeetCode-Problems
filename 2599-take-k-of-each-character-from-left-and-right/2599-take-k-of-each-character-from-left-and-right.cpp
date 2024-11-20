class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        unordered_map<char, int> count;
        // Count total occurrences of 'a', 'b', and 'c'
        for(char ch : s)
            count[ch]++;

        // If any character's count is less than k, return -1
        if(count['a'] < k || count['b'] < k || count['c'] < k)
            return -1;

        // Sliding window to find the largest valid window
        int maxWindow = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            count[s[right]]--;
            // Ensure the remaining characters outside the window are >= k
            while(count['a'] < k || count['b'] < k || count['c'] < k) {
                count[s[left]]++;
                left++;
            }
            // Update the largest valid window
            maxWindow = max(maxWindow, right - left + 1);
        }
        // The minimum removals are the complement of the largest window
        return n - maxWindow;
    }
};
