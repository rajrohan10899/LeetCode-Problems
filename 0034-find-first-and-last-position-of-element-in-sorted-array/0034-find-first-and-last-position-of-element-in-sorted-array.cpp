// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int firstOcc = -1;
//         int lastOcc = -1;
//         for(int i = 0; i < nums.size(); i++) {
//             if(nums[i] == target) {
//                 if(firstOcc == -1) {
//                     firstOcc = i;
//                     lastOcc = i;   
//                 }
//                 else {
//                     lastOcc = i;
//                 }
//             }
//         }
//         return {firstOcc, lastOcc};
//     }
// };

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2, -1);
        auto lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        auto ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin()-1;

        if(lb < nums.size() && nums[lb] == target) {
            res[0] = lb;
            res[1] = ub;
        }
        return res;
    }
};
