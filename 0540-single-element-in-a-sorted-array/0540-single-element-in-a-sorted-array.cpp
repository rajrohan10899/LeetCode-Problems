class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i+=2) {
            if(nums[i] == nums[i+1]) 
                continue;
            else 
                return nums[i];
        }
        return nums[nums.size()-1];
    }
};