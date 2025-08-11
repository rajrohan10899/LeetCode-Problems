class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int left = 0, right = 0, sum = 0, maxSumAvg = INT_MIN;
        while(right < nums.size()) {
            sum += nums[right];

            if(right - left + 1 < k) {
                right++;
            }
            else if(right - left + 1 == k) {
                maxSumAvg = max(maxSumAvg, sum);
                sum -= nums[left];
                right++;
                left++;
            }
        }
        return maxSumAvg / (double)k;
    }
};