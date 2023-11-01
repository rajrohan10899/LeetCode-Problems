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
    void solve(TreeNode* root,unordered_map<int,int> &mapp)
    {
        if(!root)
           return  ;

        solve(root->left,mapp) ;
        mapp[root->val]++ ;
        solve(root->right,mapp) ;
    }
    vector<int> findMode(TreeNode* root) 
    {
        unordered_map<int,int> mapp ;
        vector<int> ans ;
        int freq = 0 ;

        solve(root,mapp) ;
        
        for(auto it = mapp.begin() ; it != mapp.end() ; it++)
        {
            // cout<<it->first<<" "<<it->second<<endl ;
            if(it->second > freq)
            {
                ans.clear() ;
                ans.push_back(it->first) ;
                freq = it->second ;
            }
            else if(it->second == freq)
                ans.push_back(it->first) ; 
        }
        return ans ;
    }
};