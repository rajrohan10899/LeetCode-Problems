class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if((nums[i] % 2) == (nums[j] % 2)) 
                    return false;
                    break;
            }
        }
        return true;
    }
};