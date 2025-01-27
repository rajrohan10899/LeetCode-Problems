class Solution {
public:
    void letterCombination(int idx, string &digits, string &temp, unordered_map<char, string> mpp, vector<string> &result) {

        if(idx == digits.length()) {
            result.push_back(temp);
            return;
        }

        char ch = digits[idx];
        string str = mpp[ch];

        for(int i=0; i<str.length(); i++) {

            //do
            temp.push_back(str[i]);
            //explore
            letterCombination(idx+1, digits, temp, mpp, result);
            //undo
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        if(digits.length() == 0) return {};

        string temp = "";

        unordered_map<char, string> mpp;

        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        letterCombination(0, digits, temp, mpp, result);

        return result;
    }
};