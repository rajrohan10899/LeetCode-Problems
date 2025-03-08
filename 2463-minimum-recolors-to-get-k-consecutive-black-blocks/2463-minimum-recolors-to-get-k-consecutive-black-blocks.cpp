class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minOp = INT_MAX;
        for(int i = 0; i <= blocks.length()-k; i++) {
            int CntWhiteBlock = 0;
            for(int j = i; j-i+1 <= k; j++) {
                if(blocks[j] == 'W') {
                    CntWhiteBlock++;
                }
            }
            minOp = min(minOp, CntWhiteBlock);
        }
        return minOp;
    }
};