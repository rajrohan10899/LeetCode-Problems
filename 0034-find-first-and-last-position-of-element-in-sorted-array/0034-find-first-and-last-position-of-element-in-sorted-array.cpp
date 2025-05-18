class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOcc = -1;
        int lastOcc = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                if(firstOcc == -1) {// checking that is it still -1 : skip ? update firstOcc
                    firstOcc = i;
                    lastOcc = i;   
                }
                else {
                    lastOcc = i;
                }
            }
        }
        return {firstOcc, lastOcc};
    }
};


