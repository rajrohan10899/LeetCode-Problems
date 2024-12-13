class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int, int>> vec(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            vec[i] = {nums[i], i};
        }

        sort(vec.begin(), vec.end()); // (1,1), (2,0), (2,5), (3,2), (4,3), (5,4)

        long score = 0;
        vector<int> vis(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            int smallestEle = vec[i].first;
            int index = vec[i].second;
            if(vis[index] == 0) {
                vis[index] = 1;
                score += smallestEle;

                if(index - 1 >= 0) {
                    vis[index - 1] = 1;
                }
                if(index + 1 < nums.size()) {
                    vis[index + 1] = 1;
                }
            }
        }
        return score;
    }
};