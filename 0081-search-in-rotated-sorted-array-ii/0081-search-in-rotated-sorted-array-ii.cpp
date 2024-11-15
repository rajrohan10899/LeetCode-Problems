class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) { 
            int mid = start + (end - start) / 2;
            
            if (nums[mid] == target)
                return true;

            //For dupilcates we only have to update left and right pointer.
            if ((nums[start] == nums[mid]) && (nums[end] == nums[mid])) {
                start++;
                end--;
            } 
            else if (nums[start] <= nums[mid]) {

                // target is in first  half
                if ((nums[start] <= target) && (nums[mid] > target)) {
                    end = mid - 1;
                } 
                else {
                    start = mid + 1;
                }
            } 
            else { 
                // target is in second half
                if ((nums[end] >= target) && (nums[mid] < target)) {
                    start = mid + 1;
                } 
                else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};
