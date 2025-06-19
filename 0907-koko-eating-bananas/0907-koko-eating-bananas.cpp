typedef long long ll;
class Solution {
public:
    ll calcTotalHour(vector<int>& piles, int hour) {
        ll totalH = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalH += ceil((double)(piles[i]) / (double)(hour));
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = *max_element(piles.begin(), piles.end());

        int low = 1, high = maxi, ans = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;

            ll reqTime = calcTotalHour(piles, mid);

            if (reqTime <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};