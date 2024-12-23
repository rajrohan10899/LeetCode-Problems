/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// Approach - Simple BFS with hidden problem
// T.C : O(n + level * wlogw), level = total levels, w = number of nodes in a
// level S.C : O(n)
class Solution {
public:
    int countMinSwapsToSort(vector<int>& vec) {
        int swaps = 0;
        vector<int> sortedVec(vec.begin(), vec.end());

        sort(sortedVec.begin(), sortedVec.end());

        unordered_map<int, int> mpp; // nums[i] -> i
        for(int i = 0; i < vec.size(); i++) {
            mpp[vec[i]] = i;
        }

        for(int i = 0; i < vec.size(); i++) {
            if(vec[i] == sortedVec[i])
                continue; // no need of swapping

            int currIdx = mpp[sortedVec[i]];
            mpp[vec[i]] = currIdx;
            mpp[vec[currIdx]] = mpp[vec[i]];
            swap(vec[currIdx], vec[i]);
            swaps++;
        }
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        int res = 0;

        while (!que.empty()) {
            int n = que.size(); // total nodes in current level
            vector<int> vec;

            while(n--) {
                TreeNode* temp = que.front();
                que.pop();
                vec.push_back(temp->val);

                if(temp->left) 
                    que.push(temp->left);
                if (temp->right) 
                    que.push(temp->right);
            }
            res += countMinSwapsToSort(vec);
        }
        return res;
    }
};
