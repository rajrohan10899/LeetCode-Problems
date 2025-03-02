class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            // case 1: id's are same, and we have to add value
            if(nums1[i][0] == nums2[j][0]){
                res.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++; j++;
            }
            // case 2: id1 is smaller than id2, id1 to be considered 
            else if(nums1[i][0] < nums2[j][0]){
                res.push_back(nums1[i]);
                i++;
            }
            // case 3: id1 is greater than id2, id2 to be considered
            else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        // case 4: exhaustion of nums2.size(), nums1 to be copied directly in res 
        while(i < nums1.size()){
            res.push_back(nums1[i]);
            i++;
        }
        // case 5: exhaustion of nums1.size(), nums2 to be copied directly in res 
        while(j < nums2.size()){
            res.push_back(nums2[j]);
            j++;
        }
        return res;
    }
};