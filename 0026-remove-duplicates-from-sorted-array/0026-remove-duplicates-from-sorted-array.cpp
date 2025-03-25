class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Brute Force:
        set<int>st;
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        int idx = 0;
        for(auto &it : st) {
            nums[idx] = it;
            idx++;
        }
        return st.size();
    }
};