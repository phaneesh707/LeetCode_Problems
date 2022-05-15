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
            return -1;
        int r = height(root->right);
        int l = height(root->left);
        if(l>r)
            return l+1;
        else
            return r+1;
    }
    
    void inorder(TreeNode* root,int h,int& sum,int count){
        if(root!=NULL){
            inorder(root->left,h,sum,count+1);
            if(count==h)
                sum+=root->val;
            inorder(root->right,h,sum,count+1);
        }
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        inorder(root,height(root),sum,0);
        return sum;
    }
};