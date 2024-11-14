class Solution {
public:
    bool possToDist(int x, vector<int>& quantities, int shops) {
        for(auto &products : quantities) {
            // ceil(products / x) without using floating-point division
            shops -= (products + x - 1) / x;
            if(shops < 0) {
                return false;
            }
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        int res = 0;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(possToDist(mid, quantities, n)) {
                res = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return res;
    }
};