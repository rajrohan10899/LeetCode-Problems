typedef long long ll;
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        unordered_map<int, int> mpp;
        int i = 0, j = 0; 
        ll pairs = 0, res = 0;

        while(j < nums.size()) {
            pairs += mpp[nums[j]];
            mpp[nums[j]]++;

            while(pairs >= k) {
                res += (nums.size()- j);
                mpp[nums[i]]--;
                pairs -= mpp[nums[i]];
                i++;
            }
            j++;
        }
        return res;
    }
};