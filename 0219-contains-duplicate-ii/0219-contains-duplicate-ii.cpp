class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>st;
        int i = 0, j = 0;
        while(j < nums.size()) {
            //Invalid.
            if(abs(i-j) > k) {
                //window shrink
                st.erase(nums[i]);
                i++;
            }
            //Duplication.
            if(st.find(nums[j]) != st.end()) {
                return true;
            }
            st.insert(nums[j]);
            j++;
        }
        return false;
    }
};