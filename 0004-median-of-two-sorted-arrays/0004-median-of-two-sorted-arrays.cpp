class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums3;
        int i = 0, j = 0;
        while(i< nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) nums3.push_back(nums1[i++]);
            else nums3.push_back(nums2[j++]);
        }
        while(i < nums1.size()) nums3.push_back(nums1[i++]);
        while(j < nums2.size()) nums3.push_back(nums2[j++]);

        int n = nums1.size()+nums2.size();
        if(n % 2 == 1) return nums3[n/2]; 

        return (double)((double)(nums3[n/2]) + (double)(nums3[n/2-1]))/2.0;
    }
};