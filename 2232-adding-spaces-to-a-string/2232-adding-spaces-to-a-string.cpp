class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string spacedStr = "";
        // spacedStr += s[0];
        int j = 0;
        for(int i = 0; i < s.length(); i++) {
            if(j < spaces.size() && i == spaces[j]) {
                spacedStr += " ";
                j++;
            }
            spacedStr += s[i];
        }
        return spacedStr;
    }
};