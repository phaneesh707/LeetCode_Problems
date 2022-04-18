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
    void inorder(TreeNode* root,int k,int& val,int& flag){
        // static int flag = 0;
        if(root!=NULL){
            inorder(root->left,k,val,flag);
            flag++;
            if(k==flag){
                
                val = root->val;
                return;
            }
                
            inorder(root->right,k,val,flag);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int val=0,flag=0;
        inorder(root,k,val,flag);
        return val;
        
    }
};