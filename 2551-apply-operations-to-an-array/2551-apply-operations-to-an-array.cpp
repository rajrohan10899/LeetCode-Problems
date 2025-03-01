class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
                i++;
            }
        }
        //count of non zeroes element in the array.
        int count = 0;

        //traverse the array .
        //If element encountered is non-zero, then replace the element at index 'count' with this element.

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                nums[count] = nums[i];
                count++;
            }
        }
        // Fill remaining positions in the array with 0
        while (count < nums.size()) 
        {
            nums[count] = 0;
             count++;
        }
        return nums;
    }
};