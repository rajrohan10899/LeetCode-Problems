class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int j = 0;  j < nums.size(); j++) {
            if(nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        // for(int i = 0; i < temp.size(); i++) {
        //     nums[i] = temp[i];
        // }
        return i;
    }
};