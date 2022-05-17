/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ref=NULL;
    void inorder(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(cloned){
            inorder(original->left,cloned->left,target);
            if(original == target){
                ref = cloned;
                cout<<ref->val;
                return;
            }
            inorder(original->right,cloned->right,target);
            
        }
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        inorder(original,cloned,target);
        return ref;
    }
};