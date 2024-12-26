class Solution {
public:
    int solve(int idx, int tar, vector<int>&nums, vector<vector<int>> &dp) {

        if(idx == 0) {
            if(tar == 0 && nums[0] == 0) return 2;
            if(tar == 0 || tar == nums[0]) return 1;
            return 0;
        }
        if(dp[idx][tar] != -1) return dp[idx][tar];

        int notTake = solve(idx-1, tar, nums, dp);

        int take = 0;
        if(nums[idx] <= tar) {
            take = solve(idx-1, tar - nums[idx], nums, dp);
        }
        return dp[idx][tar] = notTake + take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int totSum = 0;
        for(auto &it : nums) 
            totSum += it;

        if(totSum - target < 0) return 0; // for checking negative

        if((totSum - target) % 2) return 0; // for checking odd

        int tar = (totSum-target)/2;
        vector<vector<int>>dp(nums.size(), vector<int>(tar+1, -1));
        return solve(nums.size()-1, tar, nums, dp);
    }
};