class Solution {
public:
    int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        // unordered_map<char, int> mppInitialS;
        vector<int>mppInitialS(26, 0);
        for(int i = 0; i < s.length(); i++) {
            mppInitialS[s[i]- 'a']++; // character se index nikalte h aise
        }

        // Transformation Perform:
        for(int transform = 1; transform <= t; transform++) {
            // unordered_map<char, int>mppTemp;
            vector<int>mppTemp(26, 0);

            for(int i = 0; i < 26; i++) {
                char ch = i + 'a'; // index se character chahie h.
                int freq = mppInitialS[i];

                if(ch != 'z') {
                    mppTemp[(ch+1) - 'a'] = (mppTemp[(ch+1) - 'a'] + freq) % MOD;
                }
                else { //ch == z.
                    mppTemp['a' - 'a'] = (mppTemp['a'- 'a'] + freq) % MOD;
                    mppTemp['b' - 'a'] = (mppTemp['b' - 'a'] + freq) % MOD;
                }
            }
            mppInitialS = move(mppTemp);
        }
        int freqCnt = 0;
        for(int i = 0; i < 26; i++) {
            freqCnt = (freqCnt + mppInitialS[i]) % MOD;
        }
        return freqCnt;
    }
};