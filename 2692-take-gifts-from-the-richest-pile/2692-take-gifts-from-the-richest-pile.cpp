class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>maxHeap(gifts.begin(), gifts.end()); // populate gifts in mxHeap.

        long long beforeOpSum = 0;
        for(auto &gift : gifts) {
            beforeOpSum += gift;
        }
        long long afterOpSum = 0;
        while(k > 0) {
            int maxEle = maxHeap.top();
            maxHeap.pop();

            int rem = sqrt(maxEle);
            afterOpSum += maxEle - rem;
            maxHeap.push(rem);

            k--;

        }
        return beforeOpSum - afterOpSum;
    }
};