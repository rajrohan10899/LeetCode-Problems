class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            // Step 1: Check if the middle element is the target
            if(nums[mid] == target) return mid;

            // Step 2: Determine which half of the array is sorted
            if(nums[low] <= nums[mid]) {
                // Left half [low...mid] is sorted

                // Step 3: Check if the target lies within the sorted left half
                if(nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // Move to the left half
                } else {
                    low = mid + 1; // Move to the right half
                }
            } else {
                // Right half [mid...high] is sorted

                // Step 4: Check if the target lies within the sorted right half
                if(nums[mid] < target && target <= nums[high]) {
                    low = mid + 1; // Move to the right half
                } else {
                    high = mid - 1; // Move to the left half
                }
            }
        }
        // Target not found
        return -1;
    }
};
