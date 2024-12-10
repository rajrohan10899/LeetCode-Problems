class Solution {
public:
    bool isSpecial(string& str) {
        char firstChar = str[0];
        for(char ch : str) {
            if(ch != firstChar)
                return false;
        }
        return true;
    }
    int maximumLength(string s) {
        int maxlen = -1;

        unordered_map<string, int> freq;
        for(int i = 0; i < s.length(); i++) {
            string currStr = "";
            for(int j = i; j < s.length(); j++) {
                currStr += s[j];
                if(isSpecial(currStr)) {
                    freq[currStr]++;
                    if(freq[currStr] >= 3) {
                        maxlen = max(maxlen, j-i+1);
                    }
                }
            }
        }
        return maxlen;
    }
};