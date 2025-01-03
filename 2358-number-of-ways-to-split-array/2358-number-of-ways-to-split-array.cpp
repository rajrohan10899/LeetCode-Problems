//Approach-1 (Using cummulativeSum array/Prefix Sum Array)
//T.C : O(N)
//S.C : O(N)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
     
        vector<long long> cumSum(nums.size());
        cumSum[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            cumSum[i] = cumSum[i - 1] + nums[i];
        }

        int split = 0;
 
        for (int i = 0; i < nums.size() - 1; i++) {
            
            long long leftSum = cumSum[i];
            
            long long rightSum = cumSum[nums.size() - 1] - cumSum[i];

            if (leftSum >= rightSum) {
                split++;
            }
        }

        return split;
    }
};
