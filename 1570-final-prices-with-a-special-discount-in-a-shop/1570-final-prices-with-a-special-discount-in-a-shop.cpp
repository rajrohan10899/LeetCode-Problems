//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        vector<int> res(prices.begin(), prices.end());
        for(int i = 0; i < prices.size(); i++) {
            for(int j = i + 1; j < prices.size(); j++) {
                if(prices[j] <= prices[i]) {

                    res[i] -= prices[j];
                    break;
                }
            }
        }
        return res;
    }
};