//Approach-2 (Using max-heap (priority_queue)) (worst case :O(n*log(n)) when elements are in ascending order)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            
            //remove the max elements which are out of window size
            while(!pq.empty() && pq.top().second <= i-k) {
                pq.pop();
            }
            pq.push({nums[i], i}); //we will always find the max element at top

            if(i >= k-1) {
                res.push_back(pq.top().first);
            }
        }
        return res;
    }
};
