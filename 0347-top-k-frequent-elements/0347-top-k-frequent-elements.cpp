class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //1. store freq of element in map.
        unordered_map<int, int> mpp;
        for (auto num : nums) {
            mpp[num]++;
        }
        //2.Define heap.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it : mpp)
        {
            pq.push({it.second, it.first});
            if (pq.size() > k)
                pq.pop();
        }
        //3. define ans vector.
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};