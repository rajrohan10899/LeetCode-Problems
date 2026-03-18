class Solution {
public:
    // Step: 3
    bool allZero(vector<int>& storePchar) {
        for (int& i : storePchar) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {

        // Step 1:
        vector<int> storePchar(26, 0);
        for (int i = 0; i < p.length(); i++) {
            char ch = p[i];
            storePchar[ch - 'a']++;
        }

        // Step: 2
        int i = 0, j = 0;
        vector<int> res;
        while (j < s.length()) {
            // calculation
            storePchar[s[j] - 'a']--;

            // check for window size
            if (j - i + 1 < p.length()) {
                j++;
            }

            // If Reached Window size
            else if (j - i + 1 == p.length()) {

                if (allZero(storePchar)) {
                    res.push_back(i);
                }
                storePchar[s[i] - 'a']++;
                i++; j++;
            }
        }
        return res;
    }
};