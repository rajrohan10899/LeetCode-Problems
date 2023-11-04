class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        for (int i = 0; i < left.size(); i++) {
            result = max(result, left[i]);
        }
        for (int j = 0; j < right.size(); j++) {
            result = max(result, n - right[j]);
        }
        return result;
    }
};
