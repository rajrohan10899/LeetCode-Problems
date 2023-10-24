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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == NULL) 
            return res;
            
        queue<TreeNode*> bfs;
        bfs.push(root);

        while(!bfs.empty()){
            int size = bfs.size();
            int maxi = INT_MIN;

            while(size--){
                TreeNode* temp = bfs.front();
                bfs.pop();

                if(temp->left != NULL){
                    bfs.push(temp->left);
                }
                if(temp->right != NULL){
                    bfs.push(temp->right);
                }
                maxi = max(maxi, temp->val);
            }
            res.push_back(maxi);

        }
        return res;
    }
};