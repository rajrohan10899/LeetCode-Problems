class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int> cumSum(nums.size(), 0);
        // cumSum[i] = total count of violating indices till index i
        cumSum[0] = 0;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] % 2 == nums[i - 1] % 2) { //violating index
                cumSum[i] = cumSum[i - 1] + 1;
            } 
            else {
                cumSum[i] = cumSum[i - 1];
            }
        }

        vector<bool> res(queries.size(), false);
        int i = 0;
        for(vector<int>& query : queries) {
            int start = query[0];
            int end = query[1];

            if(cumSum[end] - cumSum[start] == 0) {
                res[i] = true;
            }
            i++;
        }
        return res;
    }
};