class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>resMax(matrix.size(), vector<int>(matrix.size(), 0));
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix.size(); j++) {
                resMax[j][matrix.size()-1-i] = matrix[i][j];
            }
        }
        matrix = resMax;
    }
};