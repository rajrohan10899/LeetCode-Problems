//Approach-1 (Brute Force Using unordered_set extra space)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    vector<int> minOperations(string boxes) {
        unordered_set<int> st;

        for(int i = 0; i < boxes.length(); i++) {
            if(boxes[i] == '1') {
                st.insert(i);
            }
        }

        vector<int> res(boxes.length(), 0);

        for(int i = 0; i < boxes.length(); i++) {
            for(auto &idx : st) {
                res[i] += abs(i - idx);
            }
        }

        return res;

    }
};