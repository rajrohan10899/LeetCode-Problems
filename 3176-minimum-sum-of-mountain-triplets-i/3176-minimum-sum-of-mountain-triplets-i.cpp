class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int tripletSum = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] < nums[j] && nums[k] < nums[j]) {
                        tripletSum = min(tripletSum, nums[i] + nums[j] + nums[k]);
                    }
                }
            }
        }
        if(tripletSum == INT_MAX) {
            return -1;
        }
        return tripletSum;
    }
};
