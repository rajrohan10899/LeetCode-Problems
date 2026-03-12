class Solution {
public:
    // Technique: two-pointer from the end so that merge can happen in-place.
    // Time complexity: O(m+n).
    // Space complexity: O(1).
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int left = m-1, right = n-1, idxPos = m + n - 1;

        while(left >= 0 && right >= 0) {

            if(nums1[left] < nums2[right])  {
                nums1[idxPos] = nums2[right];
                right--;
                idxPos--;
            }
            else {
                nums1[idxPos] = nums1[left];
                left--;
                idxPos--;
            }
        }
// Case: Exahustion Condition.
        while(left >= 0) {
            nums1[idxPos] = nums1[left];
            left--;
            idxPos--;
        }
        while(right >= 0) {
            nums1[idxPos] = nums2[right];
            right--;
            idxPos--;
        }
    }
};