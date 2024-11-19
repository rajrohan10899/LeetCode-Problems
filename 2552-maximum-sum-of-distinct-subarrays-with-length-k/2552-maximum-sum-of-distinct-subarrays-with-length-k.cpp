typedef long long ll;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll res = 0;
        ll currWindowSum = 0;
        unordered_set<int>st;

        int i = 0, j = 0; //1, 5, 4, 2, 9, 9, 9
        while(j < nums.size()) {
            while(st.count(nums[j])) {
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            currWindowSum += nums[j];
            st.insert(nums[j]);

            if(j-i+1 == k) {
                res = max(res, currWindowSum);
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};