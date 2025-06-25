class Solution {
public:
    int solve(vector<int>& weights, int mid) {
        int days = 1, shipLoad = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] + shipLoad > mid) {
                shipLoad = weights[i];
                days = days + 1;
                
            } else {
                shipLoad += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int res = 0;

        while (low <= high) {
            int mid = low + (high - low)/2;

            int daysReq = solve(weights, mid);
            if(daysReq <= days) {
                res = mid;
                high = mid -1;
            }
            else {
                low = mid + 1;
            }
           
        }
        return res;
    }
};