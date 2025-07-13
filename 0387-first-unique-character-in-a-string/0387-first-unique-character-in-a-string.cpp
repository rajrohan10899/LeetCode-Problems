class Solution {
public:
    int firstUniqChar(string s) {
        int charFreq[26] = {0};
        queue<pair<char, int>> que;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            charFreq[ch - 'a']++;
            que.push({ch, i});

            while (!que.empty() && charFreq[que.front().first - 'a'] > 1) {
                que.pop();
            }
        }
        if (!que.empty()) {
            return que.front().second;
        }
        return -1;
    }
};