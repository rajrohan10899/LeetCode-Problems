class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size(), col = box[0].size();
        vector<vector<char>> rotateBox(col, vector<char>(row, '.'));
        
        for(int i = 0; i < row; i++) {
            int bottom = col - 1;
            for(int j = col - 1; j >= 0; j--) {
                if(box[i][j] == '#') {
                    rotateBox[bottom][row - 1 - i] = '#';
                    bottom--;
                } 
                else if(box[i][j] == '*') {
                    rotateBox[j][row - 1 - i] = '*';
                    bottom = j - 1;
                }
            }
        }
        return rotateBox;
    }
};