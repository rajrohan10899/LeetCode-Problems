class Solution { 
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = INT_MIN;
        int maxValue = values[0] + 0;

        for(int i = 1; i < values.size(); i++) {  
            res = max(res, maxValue + values[i] - i);
            maxValue = max(maxValue, values[i] + i);
        }
        return res;
    }
};