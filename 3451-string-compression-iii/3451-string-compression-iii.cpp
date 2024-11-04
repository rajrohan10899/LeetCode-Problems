class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int cnt = 1;
        for(int i = 0; i < word.length(); i++) {
            if(word[i] == word[i+1] && cnt < 9) {
                cnt++;
            }
            else {
                comp += to_string(cnt) + word[i];
                cnt = 1;
            }
        }
        return comp;
    }
};