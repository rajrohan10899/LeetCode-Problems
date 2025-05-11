class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3) 
            return false;

        int cntConsecutiveOdd = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] % 2 != 0) {
               cntConsecutiveOdd++;
            }
            else {
                cntConsecutiveOdd = 0;
            }
            if(cntConsecutiveOdd == 3) {
                return true;
            }
        }
        return false;
    }
};