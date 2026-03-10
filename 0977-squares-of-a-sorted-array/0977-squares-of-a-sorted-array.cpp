class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int>res(nums.size());

        int left = 0, right = nums.size()-1, idxPos = nums.size()-1;

        while(left <= right) {

            if(abs(nums[left]) > abs(nums[right])) {
                res[idxPos] = nums[left] * nums[left];
                left++;
            }
            else {
                res[idxPos] = nums[right] * nums[right];
                right--;
            }
            idxPos--;
        }
        return res;
    }
};

// Time Complexity: O(N) --> Space Complexity: O(N) because we are return an array of size N.