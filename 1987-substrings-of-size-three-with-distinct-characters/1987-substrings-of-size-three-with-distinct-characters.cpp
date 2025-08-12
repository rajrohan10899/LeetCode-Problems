class Solution {
public:
    
    bool isGood(string sub) {
        for(int i = 0; i < sub.size(); i++) {
            for(int j = i + 1; j < sub.size(); j++) {
                if(sub[i] == sub[j]) {
                    return false;
                }
            }
        }
        return true;
    }
    int countGoodSubstrings(string s) {

        if (s.size() < 3) 
            return 0;

        int count = 0;
        // int k = 3;
        for(int i = 0; i <= s.length() - 3; i++) {
            string sub = "";
            for(int j = i; j < i + 3; j++) {
                sub += s[j];
            }
            if(isGood(sub)) {
                count++;
            }
        }
        return count;
    }
};