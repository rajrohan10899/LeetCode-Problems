class Solution {
public:
    bool binarySearch(vector<int> &mat, int target) {
        int low = 0, high = mat.size()-1;
        while(low <= high) {
            int mid = (low+high)/2;
            if(mat[mid] == target) return true;
            else if(mat[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] <= target && target <= matrix[i][matrix[0].size()-1]) {
                return binarySearch(matrix[i], target);
            }
        }
        return false;
    }
};