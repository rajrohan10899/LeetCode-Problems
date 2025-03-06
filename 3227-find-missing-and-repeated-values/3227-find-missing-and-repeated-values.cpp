class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int>mpp;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                mpp[grid[i][j]]++;
            }
        }
        int repeated = 0, missing = 0;
        for(int i = 1; i <= n*n; i++) {
            if(mpp[i] == 2) {
                repeated = i;
            }
            if(mpp[i] == 0) {
                missing = i;
            }
        }
        return {repeated, missing};
    }
};