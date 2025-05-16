class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Brute-Force:
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                return i; // target mil gaya 
            }
            else if(nums[i] > target) {
                return i; // yahan insert kar sakte ho
            }
        }
        return nums.size(); // target sabse bada hai, end me insert hoga
    }
};