class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maxBit) {
        vector<int>res;
        //1.
        int currXor = 0;
        for(int i = 0; i < nums.size(); i++) {
            currXor ^= nums[i];
        }
        //2.
        int maxValK = pow(2, maxBit) - 1;
        for(int i = 0; i < nums.size(); i++) {
            res.push_back(maxValK ^ currXor);
            //3.
            currXor ^= nums[nums.size()-1-i];
        }
        return res;
    }
};