class Solution {
public:
    int SubArrCntLessThanEqualToK(vector<int>& nums, int k) {
        int i = 0, j = 0, subArrCnt = 0;
        unordered_map<int, int>mpp;
        while(j < nums.size()) {
            mpp[nums[j]]++;

            while(mpp.size() > k) {
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) 
                    mpp.erase(nums[i]);
                i++;
            }
            subArrCnt += (j-i+1);
            j++;
        }
        return subArrCnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return SubArrCntLessThanEqualToK(nums, k) - SubArrCntLessThanEqualToK(nums, k-1);
    }
};