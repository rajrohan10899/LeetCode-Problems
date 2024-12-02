class Solution {
public:
    int SumLessThanEqualK(vector<int>& nums, int goal) {
        if(goal < 0) 
            return 0;
        int i = 0, j = 0, sum = 0, cnt = 0;
        while(j < nums.size()) {
            sum += nums[j];
            while(sum > goal) {
                sum -= nums[i];
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Avoid negative sum cases
        return SumLessThanEqualK(nums, goal) - SumLessThanEqualK(nums, goal-1);
    }
};