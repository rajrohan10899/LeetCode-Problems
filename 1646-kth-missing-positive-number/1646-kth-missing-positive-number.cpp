class Solution {
public:
/*
You’re checking for how many numbers from 1 to arr[i] are missing.

If arr[i] <= k, that means the current number in the array is not the kth missing number yet, so you increment k (since one missing number is skipped because the array has the number arr[i]).

When arr[i] > k, it means that the k-th missing number lies before arr[i]. So we break and return k.
*/
    int findKthPositive(vector<int>& arr, int k) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] <= k) {
                k++;
            }
            else {
                break;
            }
        }
        return k;
    }
};