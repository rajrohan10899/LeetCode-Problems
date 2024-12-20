/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        int level = 0;
        while(!que.empty()) {
            int n = que.size();

            vector<TreeNode*> levelNodes;
            while(n--) {
                TreeNode* temp = que.front();
                que.pop();

                levelNodes.push_back(temp);

                if(temp -> left) {
                    que.push(temp->left);
                }
                if(temp->right) {
                    que.push(temp->right);
                }
            }
            if(level % 2 == 1) {
                //swap the level values.
                int left = 0, right = levelNodes.size()-1;
                while(left <= right) {
                    int tempVal = levelNodes[left]->val;
                    levelNodes[left]->val = levelNodes[right]->val;
                    levelNodes[right]->val = tempVal;
                    left++; right--;
                }
            }
            level++;
        }
        return root;
    }
};