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
        if(root==NULL)
            return 0;
        int l =1 + height(root->left);
        int r =1 + height(root->right);
        
        return max(l,r);
    }
    
    void inorder(TreeNode* root,int& maxi){
        if(root){
            inorder(root->left,maxi);
            maxi = max(maxi,height(root->left)+height(root->right));
            inorder(root->right,maxi);
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        inorder(root,maxi);
        return maxi;
        
    }
};