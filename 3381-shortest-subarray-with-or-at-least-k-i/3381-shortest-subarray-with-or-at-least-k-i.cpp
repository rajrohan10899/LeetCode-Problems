class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int shortLen = INT_MAX;;
        for (int i = 0; i < nums.size(); i++) {
            int currentOr = 0; 
            for(int j = i; j < nums.size(); j++) {
                currentOr |= nums[j]; 

            if(currentOr >= k) 
                shortLen = min(shortLen, j-i+1); // Update minimum length
            }
        }
        return shortLen == INT_MAX ? -1 : shortLen;
    }
};