class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indgree(n, 0);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            // u--->v arrow h that means indgres increase.
            indgree[v]++;  
        }
        int champion = -1;
        int cntChamp = 0;
        for(int i = 0; i < n; i++) {
            if(indgree[i] == 0) {
                champion = i;
                cntChamp++;

                if(cntChamp > 1) {
                    return -1;
                }
            }
        }
        return champion;
    }
};