class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int minOp = 0;
        while(true) {
            unordered_set<int> unique_elements(nums.begin(), nums.end());
            if(unique_elements.size() == nums.size()) {
                break;
            }
            if(nums.size() <= 3) {
                nums.clear();
            } 
            else {
                nums.erase(nums.begin(), nums.begin() + 3);
            }
            minOp++;   
        }
        return minOp;
    }
};