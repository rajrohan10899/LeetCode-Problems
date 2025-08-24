// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//         int longestOnesLen = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             int zeroesCnt = 0;
//             for (int j = i; j < nums.size(); j++) {
//                 if (nums[j] == 0) {
//                     zeroesCnt++;
//                 }
//                 if (zeroesCnt <= 1) {
//                     longestOnesLen = max(longestOnesLen, j - i);
//                 }
//             }
//         }
//         return longestOnesLen;
//     }
// };

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int i = 0, j = 0, longestOnesLen = 0, zeroesCnt = 0;
        while(j < nums.size()) {
            if(nums[j] == 0) {
                zeroesCnt++;
            }
            if(zeroesCnt > 1) {
                if(nums[i] == 0) {
                    zeroesCnt--;
                }
                i++;
            }
            if(zeroesCnt <= 1) {
                longestOnesLen = max(longestOnesLen, j-i);
            }
            j++;
        }
        return longestOnesLen;
    }
};