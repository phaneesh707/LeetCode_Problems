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
    
    int height(TreeNode* root){
        if(root == NULL) 
            return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    
    
    void dfs(TreeNode* root,bool& res){
        if(root){
            dfs(root->left,res);
            if(abs(height(root->left)-height(root->right)) > 1)
                res = false;
            dfs(root->right,res);
        }
    }
    
    bool isBalanced(TreeNode* root) {
        bool res = true;
        dfs(root,res);
        return res;
    }
};