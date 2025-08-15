class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> deq;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {

            //remove the max elements from front which are out of window size
            while(!deq.empty() && deq.front() <= i-k) {
                deq.pop_front();
            }
            
            while(!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }
            
            deq.push_back(i);
            if(i >= k-1) { //Only when the window size first gets equal or greater than k
                res.push_back(nums[deq.front()]); 
            }
        }
        return res;
    }
};