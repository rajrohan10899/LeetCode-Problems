class Solution {
public:
    //Time complexity: O(N).
    //Space Complexity: O(1).
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        while(j < nums.size()) { // O(N)
            if(nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
            else {
                j++;
            }
        }
        return i+1;
    }
};