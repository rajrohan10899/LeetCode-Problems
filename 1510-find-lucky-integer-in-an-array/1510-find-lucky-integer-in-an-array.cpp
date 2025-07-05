class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i = 0; i < arr.size(); i++) {
            mpp[arr[i]]++;
        }
        int res = -1;
        for(auto &it : mpp) {
            if(it.first == it.second) {
                res = max(res, it.first);
            }
        }
        return res;
    }
};