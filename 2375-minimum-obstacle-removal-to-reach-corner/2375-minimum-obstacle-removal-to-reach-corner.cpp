//Approach (Using Dijkstra's Algorothm - Assuming obstacle with edge weight 1 and empty with 0)
//T.C : O(m*n log(m*n))
//S.C : O(m*n)
class Solution {
public:
    #define P pair<int, pair<int, int>>
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        //result[i][j] = minimum distance/obstacleCount between [0][0] to [i][j]
        result[0][0] = 0;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}}); //{wt, {i, j}}
        //O(Elog(V))
        // E = number of edges
        // V = number of vertices
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            for(auto &dir : directions) {
                int x = i + dir[0];
                int y = j + dir[1];

                if(x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                int wt = (grid[x][y] == 1) ? 1 : 0;

                if(d + wt < result[x][y]) {
                    result[x][y] = d + wt;
                    pq.push({d+wt, {x, y}});
                }
            }
        }

        return result[m-1][n-1];

    }
};
