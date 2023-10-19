class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1;
        string t1;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                s1.push_back(s[i]);
            } 
            else {
                if (!s1.empty()) {
                    s1.pop_back();
                }
            }
        }
        for (int j = 0; j < t.length(); j++) {
            if (t[j] != '#') {
                t1.push_back(t[j]);
            } 
            else {
                if (!t1.empty()) {
                    t1.pop_back();
                }
            }
        }
        return s1 == t1;
    }
};

// "ab##", t = "c#d#"

// i = 0 -> s[i] = a -> s1[a]
// i = 1 -> s[i] = b -> s1[a, b]
// i = 2 -> s[i] = '#' -> backSpace ---> s1[a] -> b removed.
// i = 3 -> s[i] = '#' -> backSpace ---> s1[""] -> a removed. s1 empty.