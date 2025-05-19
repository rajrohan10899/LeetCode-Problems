class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0, high = nums.size() - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;

            // Is the mid equals to target:
            if (nums[mid] == target) {
                return mid;
            }

            // check is the left portion of the array is sorted:
            if (nums[low] <= nums[mid]) {
                // Is the target lies in left portion ?.
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // check is the right portion of the array is sorted:
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};