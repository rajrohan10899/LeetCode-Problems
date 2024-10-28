class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end()); //conseq together.
        int currSeqCnt = 0, lastSmaller = INT_MIN, longestConsSeq = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]-1 == lastSmaller) {
                currSeqCnt += 1;
                lastSmaller = nums[i];
            }
            else if(nums[i] != lastSmaller) {
                //lets start new seq and take that element to be lstSmaller.
                currSeqCnt = 1;
                lastSmaller = nums[i];
            }
            longestConsSeq = max(longestConsSeq, currSeqCnt);
        }
        return longestConsSeq;
    }
};