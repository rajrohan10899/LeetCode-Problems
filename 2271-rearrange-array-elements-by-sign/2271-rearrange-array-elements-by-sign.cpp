class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>posEle,negEle;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) 
                negEle.push_back(nums[i]);
            else
                posEle.push_back(nums[i]);
        }
        vector<int>res(nums.size());
        int posIdx, negIdx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i % 2 == 0)
                res[i] = posEle[posIdx++];
            else 
                res[i] = negEle[negIdx++];
        }
        return res;
    }
};