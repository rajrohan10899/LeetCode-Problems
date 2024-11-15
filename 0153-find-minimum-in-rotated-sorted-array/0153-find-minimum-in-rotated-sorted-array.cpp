class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, res = INT_MAX;
    
        while (low <= high) {
            int mid = (low + high) / 2;

            // Check which part of the array is sorted
            if (nums[low] <= nums[mid]) {
                // If the left part is sorted
                // Update the result with the minimum value of the sorted part
                res = min(res, nums[low]);
                // Narrow down the search space to the right part
                low = mid + 1;
            } else {
                // If the right part is sorted
                // Update the result with the minimum value in the right sorted part
                res = min(res, nums[mid]);
                // Narrow down the search space to the left part
                high = mid - 1;
            }
        }

        // Return the smallest value found
        return res;
    }
};
