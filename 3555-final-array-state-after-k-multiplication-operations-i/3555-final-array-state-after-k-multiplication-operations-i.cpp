//Approach-1 (Brute Force)
//T.C : O(n * k)
//S.C : O(1)
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i = 0; i < k; i++) {
            int idx = 0;
            for (int j = 0; j < nums.size(); j++) {
                if(nums[j] < nums[idx]) {
                    idx = j;
                }
            }
            nums[idx] *= multiplier;
        }
        return nums;
    }
};