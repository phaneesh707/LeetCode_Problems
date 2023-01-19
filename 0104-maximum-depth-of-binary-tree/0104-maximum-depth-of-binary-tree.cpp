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
    void dfs(TreeNode* root,int level,int& maxi){
        if(root){
            maxi = max(maxi,level);
            dfs(root->left,level+1,maxi);
            dfs(root->right,level+1,maxi);
        }
    }
    
    int maxDepth(TreeNode* root) {
        int maxi = 0;
        dfs(root,1,maxi);
        return maxi;
    }
};