class Solution {
public:
    int MOD = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        
        vector<int>prefixSum(arr.size(), 0);
        prefixSum[0] = arr[0];

        for(int i = 1; i < arr.size(); i++) {
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }

        int cntODD = 0, evenCnt = 1, oddCnt = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(prefixSum[i] % 2 == 0) {
                cntODD = (cntODD + oddCnt) % MOD;
                evenCnt++;
            }
            else {
                cntODD = (cntODD + evenCnt) % MOD;
                oddCnt++;
            }
        }
        return cntODD;
    }
};