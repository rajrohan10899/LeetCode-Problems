typedef long long ll;
class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int mid, int m, int k) {
        int cntBloomFlower = 0;
        int cntBouquetFormed = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                cntBloomFlower++;
            } else {
                cntBouquetFormed += (cntBloomFlower )/ k;

                cntBloomFlower = 0;
            }
        }
        cntBouquetFormed += (cntBloomFlower) / k;
        return cntBouquetFormed >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        ll possibleValue = 1LL * m * k;

        if (possibleValue > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int res = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(bloomDay, mid, m, k)) {
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