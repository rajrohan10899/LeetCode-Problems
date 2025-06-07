class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //Using lower_bound STL Method:
        auto it = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        // int index = it - nums.begin();
        return it;
    }
};