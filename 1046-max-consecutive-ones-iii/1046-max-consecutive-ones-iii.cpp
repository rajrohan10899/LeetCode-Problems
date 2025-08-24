class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int i = 0, j = 0, maxConsecutiveOneLen = 0, zeroesCnt = 0;
        while(j < nums.size()) {
            if(nums[j] == 0) {
                zeroesCnt++;
            }
            while(zeroesCnt > k) {
                if(nums[i] == 0) {
                    zeroesCnt--;
                }
                i++;
            }
            maxConsecutiveOneLen = max(maxConsecutiveOneLen, j-i+1);
            j++;
        }
        return maxConsecutiveOneLen;
    }
};