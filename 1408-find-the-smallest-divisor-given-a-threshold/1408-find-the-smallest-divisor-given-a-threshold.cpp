class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, int threshold) {
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            totalSum += ceil((double)nums[i]/mid);
        }
        return totalSum <= threshold; 
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int maxi = *max_element(nums.begin(), nums.end());
        int low = 1;
        int high = maxi;
        int res = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(mid, nums, threshold)) {
                res = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return res;
    }
};
