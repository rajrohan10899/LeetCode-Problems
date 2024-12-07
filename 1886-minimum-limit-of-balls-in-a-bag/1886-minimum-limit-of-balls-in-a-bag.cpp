//Approach (Using Binary Search in Answer - See the problem statement : It asks to Minimize the Maximum which hints towards Binary Search On Answer)
//T.C : O(nlog(MAX)), where n = length of nums, MAX = max value in nums
//S.C : O(1)
class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOps, int mid) {
        int totalOps = 0; //to bring each number <= mid

        for(int &num : nums) {
            int ops = num / mid;

            if(num % mid == 0) {
                ops -= 1;
            }
            totalOps += ops;
        }
        return totalOps <= maxOps;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        int res = high; //we have to minimize this

        //O(n * log(MAX))
        while(low <= high) {
            int mid = low + (high - low)/2;

            if(isPossible(nums, maxOperations, mid) == true) {
                res = mid;
                high = mid-1;
            } 
            else {
                low = mid+1;
            }
        }
        return res;
    }
};