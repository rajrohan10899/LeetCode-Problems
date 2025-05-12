class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> st;
        for(int i = 0; i < digits.size(); i++) {
            for(int j = 0; j < digits.size(); j++) {
                for(int k = 0; k < digits.size(); k++) {
                    if(i == j || i == k || j == k) 
                        continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if(num >= 100 && num % 2 == 0) {
                        st.insert(num);
                    }
                }
            }
        }
        vector<int>res(st.begin(), st.end());
        sort(res.begin(), res.end());
        return res;
    }
};