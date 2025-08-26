class Solution {
public:
//Optimal Approach : Prefix Sum + Map (striver solu)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int prefSum = 0, subArrCnt = 0;

        for(int i = 0; i < nums.size(); i++) {
            prefSum += nums[i];

            // This is what we are looking for in the map:
            int remove = prefSum - k;
            subArrCnt += mpp[remove];
            mpp[prefSum]++;
        }
        return subArrCnt;
    }
};