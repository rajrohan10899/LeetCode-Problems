class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divisible = 0, nonDivisible = 0;
        for(int i = 1; i <= n; i++) {
            (i % m == 0) ? (divisible += i) : (nonDivisible += i);
        }
        return nonDivisible - divisible;
    }
};
