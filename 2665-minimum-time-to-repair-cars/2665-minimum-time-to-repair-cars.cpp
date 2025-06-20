class Solution {
public:
    typedef long long ll;
    bool isPossible (vector<int>& ranks, ll mid, int cars) {

        ll totalCarsFixed = 0;
        for(int i = 0; i < ranks.size(); i++) {
            totalCarsFixed += sqrt(mid / ranks[i]);
        }
        return totalCarsFixed >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {

        int maxRank = *max_element(ranks.begin(), ranks.end());
        ll low = 1;
        ll high = 1LL * maxRank * cars * cars;
        ll res = -1;

        while(low <= high) {

            ll mid = low + (high - low) / 2;

            if(isPossible(ranks, mid, cars)) {
                res = mid;
                high = mid-1;
            }
            else {
                low = mid + 1;
            }
        }
        return res;
    }
};