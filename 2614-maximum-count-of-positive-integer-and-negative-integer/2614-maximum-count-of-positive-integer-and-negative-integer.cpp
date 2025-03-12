class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posCnt = 0, negCnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) continue;
            else if(nums[i] > 0) posCnt++;
            else negCnt++;
        }
        return max(posCnt, negCnt);
    }
};