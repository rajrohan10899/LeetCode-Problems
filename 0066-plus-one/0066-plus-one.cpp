class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int i = digits.size()-1;

        while(i >= 0) {
            if(digits[i] < 9) { //digits: 1,2,3,4,5,6,7,8
                digits[i] = digits[i] + 1;
                return digits;
            }

            //If the digits[i] is 9
            //then have to carry-forward 1 and make 9 to 0
            if(digits[i] == 9) {
                digits[i] = 0;
                i--;
            }
        }

        //travel it out of bound case, that means all nos are 9.
        //then insert that carryforwarded-1, into the beginning of the digits arr.
        digits.insert(digits.begin(), 1);

        return digits;
    }
};