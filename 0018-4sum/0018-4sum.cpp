typedef long long ll;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;

        for(int a = 0; a < nums.size(); a++) {
            if(a > 0 && nums[a] == nums[a-1]) continue;

            for(int b = a+1; b < nums.size(); b++) {
                if(b > a+1 && nums[b] == nums[b-1]) continue;

                int c = b+1;
                int d = nums.size()-1;

                while(c < d) {

                    ll sum = (ll)nums[a] + (ll)nums[b] + (ll)nums[c] + (ll)nums[d];

                    if(sum < target) {
                        c++;
                    }
                    else if(sum > target) {
                        d--;
                    }
                    else {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]}); c++; d--;

                        while(c < d && nums[c] == nums[c-1]) c++;
                        while(c < d && nums[d] == nums[d+1]) d--;

                    }
                }
            }
        }
        return res;
    }
};