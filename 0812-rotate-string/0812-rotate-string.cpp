class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        string concatenatedstr = s+s;
        for(int i = 0; i < concatenatedstr.length(); i++) {
            if(concatenatedstr.substr(i, goal.length()) == goal)
                return true;
        }
        return false;
    }
};