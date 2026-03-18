class Solution {
public:
    bool allZero(vector<int> &counter) {
        for(int &i : counter) {
            if(i != 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> counter(26, 0);
        for(int i = 0; i < p.length(); i++) {
            char ch = p[i];
            counter[ch - 'a']++; // same as solu but here i extract the ch from p.
        }
        int i = 0, j = 0;
        vector<int> res;
        while(j < s.length()) {
            counter[s[j] - 'a']--;

            if(j-i+1 == p.length()) {
                if(allZero(counter)) {
                    res.push_back(i);
                }
                counter[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};