class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>res(code.size(), 0);
        if(k == 0) {
            return res;
        }
        for(int i = 0; i < code.size(); i++) {
            if(k > 0) {
                for(int j = 1; j <= k; j++) {
                    res[i] += code[(i+j) % code.size()];
                }
            }
            else {
                // k is negative
                for(int j = 1; j <= abs(k); j++) {
                    res[i] += code[(i-j + code.size()) % code.size()];
                }
            }
        }
        return res;
    }
};