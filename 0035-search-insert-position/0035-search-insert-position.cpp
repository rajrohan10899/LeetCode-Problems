class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Optimal Approach:
        int low = 0, high = nums.size()-1, res = nums.size();
        while(low <= high) {
            int mid = (low + high)/2;

            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] > target) {
                res = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return res;
    }
};