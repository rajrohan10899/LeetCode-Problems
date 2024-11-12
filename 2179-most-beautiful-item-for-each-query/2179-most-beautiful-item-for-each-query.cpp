class Solution {
public:

    int customBinarySearch(vector<vector<int>>& items, int quePrice) {
        int l = 0;
        int r = items.size()-1;
        int maxBeauty = 0;
        while(l <= r) {
            int mid = (l+r)/2;
            if(items[mid][0] > quePrice) {
                r = mid-1;
            } else {
                maxBeauty = max(maxBeauty, items[mid][1]);
                l = mid+1;
            }
        }
        return maxBeauty;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> res(queries.size());
        sort(items.begin(), items.end());

        int maxBeautySeen = items[0][1];
        for(int i = 1; i < items.size(); i++) {
            maxBeautySeen = max(maxBeautySeen, items[i][1]);
            items[i][1] = maxBeautySeen;
        }
        for(int i = 0; i < queries.size(); i++) {
            int quePrice = queries[i];
            res[i] = customBinarySearch(items, quePrice);
        }
        return res;

    }
};