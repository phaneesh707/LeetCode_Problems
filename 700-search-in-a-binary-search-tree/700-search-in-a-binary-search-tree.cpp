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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL || root->val == val )
            return root;
       TreeNode* flag = NULL;
        TreeNode* left = searchBST(root->left,val);
        if(left!=NULL && left->val==val)
            flag = left;
        TreeNode* right = searchBST(root->right,val);
        if(right!=NULL && right->val==val)
            flag = right;
        
        return flag;
    }
};