class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0, j = 0, CntOfW = 0, minOps = INT_MAX;
        while (j < blocks.size()) {
            if (blocks[j] == 'W') {
                CntOfW++; // 3
            }
            if (j - i + 1 == k) {
                minOps = min(minOps, CntOfW);

                if (blocks[i] == 'W') {
                    CntOfW--;
                }
                i++;
            }
            j++;
        }
        return minOps;
    }
};