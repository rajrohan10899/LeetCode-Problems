class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixMax(begin(arr), end(arr));
        vector<int> suffixMin(begin(arr), end(arr));

        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], prefixMax[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], suffixMin[i]);
        }

        int chunksCount = 0;
        for (int i = 0; i < n; i++) {
            int leftMax = i > 0 ? prefixMax[i - 1] : -1;
            int rightMin = suffixMin[i];
            
            if (leftMax < rightMin) {
                chunksCount++;
            }
        }

        return chunksCount;
    }
};
