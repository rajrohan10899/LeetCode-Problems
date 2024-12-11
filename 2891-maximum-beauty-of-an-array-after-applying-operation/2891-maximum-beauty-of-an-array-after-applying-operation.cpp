/*
Approach-1 (Converting to Intervals and Using Deque)
Idea: Convert each number in the array to a range [num - k, num + k] and determine the maximum overlapping ranges.

Steps:
Generate ranges(intervals) and sort them by start points.
Use a deque to track overlapping ranges dynamically.
Update the maximum count of overlapping intervals
*/

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int, int>>intervals(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            intervals[i] = {nums[i] - k, nums[i] + k};
        }
        sort(intervals.begin(), intervals.end());
        deque<pair<int, int>>deq;
        int maxBeauty = 0;

        for(pair<int, int> interval : intervals) {
            while(!deq.empty() && deq.front().second < interval.first) {
                deq.pop_front();
            }
            deq.push_back(interval);
            maxBeauty = max(maxBeauty, (int)deq.size());
        }
        return maxBeauty;
    }
};