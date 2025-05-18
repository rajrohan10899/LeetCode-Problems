class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Solved using simple binary search:
        vector<int>res;
        int firstOcc = -1, low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target) {
                firstOcc = mid;
                high = mid-1;
            }
            else if(nums[mid] < target) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        res.push_back(firstOcc);
        int lastOcc = -1;
        low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target) {
                lastOcc = mid;
                low = mid+1;
            }
            else if(nums[mid] < target) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        res.push_back(lastOcc);
        return res;
    }
};