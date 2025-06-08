// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         for(int i = 0; i < nums.size()-1; i+=2) {
//             if(nums[i] == nums[i+1]) 
//                 continue;
//             else 
//                 return nums[i];
//         }
//         return nums[nums.size()-1];
//     }
// };

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};