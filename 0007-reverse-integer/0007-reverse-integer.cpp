typedef long long ll;
class Solution {
public:
    int reverse(int x) {
        ll revNum = 0;
        while(x != 0) {
            //Extract the digi:
            int lastDigi = x%10;
            //Add somehow 0 to extracted Digi:
            revNum = revNum*10 + lastDigi;
            //Remove the last Digi:
            x /= 10;
        }
        if(revNum > INT_MAX || revNum < INT_MIN)
            return 0;
        return revNum;
    }
};