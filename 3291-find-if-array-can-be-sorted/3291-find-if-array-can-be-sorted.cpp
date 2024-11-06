class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] <= nums[j]) 
                    continue;
                else 
                    if(__builtin_popcount(nums[i]) == __builtin_popcount(nums[j])) 
                        swap(nums[i], nums[j]);
                    else 
                        return false;
            }
        }
        return true;
    }
};