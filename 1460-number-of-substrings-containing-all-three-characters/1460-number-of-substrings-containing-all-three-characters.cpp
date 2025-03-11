class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        vector<int> vec(3, 0); // 0 -> a, 1 -> b, 2 -> c
        int i = 0, j = 0;

        while(j < s.length()) {
            char ch = s[j];
            vec[ch-'a']++;
            
            while(vec[0] > 0 && vec[1] > 0 && vec[2] > 0) {
                count += (s.length() - j);

                vec[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return count;
    }
};