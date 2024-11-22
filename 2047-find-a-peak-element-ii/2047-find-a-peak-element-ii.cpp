class Solution {
public:
    // Function to find the row index of the maximum element in the given column
    int findMaxIndex(vector<vector<int>>& mat, int col) {
        int maxValue = -1;
        int index = -1;
        for(int i = 0; i < mat.size(); i++) {
            if(mat[i][col] > maxValue) {
                maxValue = mat[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty())
            return {-1, -1}; // Handle edge cases

        int low = 0, high = mat[0].size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;

            // Find the row with the maximum element in the current column
            int maxRowIdx = findMaxIndex(mat, mid);

            // Get the values of neighbors (if they exist)
            int left = mid - 1 >= 0 ? mat[maxRowIdx][mid - 1] : -1;
            int right = mid + 1 < mat[0].size() ? mat[maxRowIdx][mid + 1] : -1;

            // Check if the current element is a peak
            if (mat[maxRowIdx][mid] > left && mat[maxRowIdx][mid] > right) {
                return {maxRowIdx, mid};
            } else if (mat[maxRowIdx][mid] < left) {
                high = mid - 1; // Move to the left half
            } else {
                low = mid + 1; // Move to the right half
            }
        }
        return {-1, -1}; // Return invalid index if no peak is found
    }
};
