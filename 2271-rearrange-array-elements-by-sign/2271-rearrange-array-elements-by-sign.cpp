class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>res(nums.size());
        int posIdx = 0, negIdx = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) {
                res[negIdx] = nums[i]; 
                negIdx += 2;
            }
            else {
                res[posIdx] = nums[i];
                posIdx += 2;
            }
        }
        return res;
    }
};