class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        while(i < start.length() || j < start.length()) {

            while(i < start.length() && start[i] == '_') i++;
            while(j < start.length() && target[j] == '_') j++;
            
            if(i == start.length() || j == start.length())
                return i == start.length()  && j == start.length();

            if(start[i] != target[j]) return false;

            if(start[i] == 'L' && i < j) return false;

            if (start[i] == 'R' && i > j) return false;

            i++; j++;
        }
        return true;
    }
};