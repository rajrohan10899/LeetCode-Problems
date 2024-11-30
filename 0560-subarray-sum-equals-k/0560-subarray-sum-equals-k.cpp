class Solution {
public:
//Optimal Approach : Prefix Sum + Map.
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int count = 0, sum = 0;
        mpp[sum] = 1;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(mpp.find(sum-k) != mpp.end()) {
                count += mpp[sum - k];
            }
            mpp[sum]++;
        }
        return count;
    }
};