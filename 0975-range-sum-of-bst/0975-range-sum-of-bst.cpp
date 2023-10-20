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
    int preOrder(TreeNode* root, int low, int high, int sum) {
        if (root == NULL)
            return 0; 
        
        if (root->val >=low && root->val <= high) {
            sum += root->val;
        }
        
        sum += preOrder(root->left, low, high, 0); 
        sum += preOrder(root->right, low, high, 0); 

        return sum; 
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        return preOrder(root, low, high, sum); 
    }
};
