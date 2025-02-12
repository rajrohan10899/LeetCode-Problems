class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;
        while(num > 0) {

            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int res = -1;
        unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++) {
            int digSum = getDigitSum(nums[i]);

            if(mpp.count(digSum)) {
                res = max(res, nums[i] + mpp[digSum]);
            }

            mpp[digSum] = max(mpp[digSum], nums[i]);
        }

        return res;
    }
};