typedef long long ll;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        ll res = 0;
        for(int i = 0; i < nums.size(); i++) {//O(n*logn)
            //(logn --> using B.S)
            int idx = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i])-nums.begin();
            int xPairs = idx - i - 1; 
            
            //(logn --> using B.S)
            idx = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i])-nums.begin();
            int yPairs = idx-i-1;

            res += yPairs - xPairs;
        }
        return res;
    }
};