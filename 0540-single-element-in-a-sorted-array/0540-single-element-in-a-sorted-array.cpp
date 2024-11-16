class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int>mpp;
        for(int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        for(auto &it : mpp) {
            if(it.second < 2) {
                return it.first;
            }
        }
        return -1;
    }
};