class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0, countSubstr = 0;
        // unordered_map<char, int>mpp;
        int hashArr[3] = {0};
        while(j < s.length()) {
            // mpp[s[j]]++;
            hashArr[s[j] - 'a']++;

            while(hashArr[0] > 0 && hashArr[1] > 0 && hashArr[2] > 0) {
            // while(mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0) {
                // yaha trick hai:
                // Agar [i...j] ek valid substring hai (contains a,b,c)
                // to j se leke end tak jitne bhi substrings bante hain 
                // wo sab valid hain.
                countSubstr += (s.length() - j);
                
                hashArr[s[i] - 'a']--;
                // mpp[s[i]]--;
                i++;
            }
            j++;
        }
        return countSubstr;
    }
};