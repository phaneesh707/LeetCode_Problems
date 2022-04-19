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
    int i=0;
    void inorder(TreeNode* root,vector<int>& buffer){
        if(root!=NULL){
            inorder(root->left,buffer);
            buffer.push_back(root->val);
            inorder(root->right,buffer);
        }
    }
    
    void modify_bst(TreeNode* root,vector<int>& buffer){
        if(root!=NULL){
            modify_bst(root->left,buffer);
            // buffer.push_back(root->val);
            root->val = buffer[i++];
            modify_bst(root->right,buffer);
        }
    }
    
    
    void recoverTree(TreeNode* root) {
        vector<int> buffer;
        inorder(root,buffer);
        sort(buffer.begin(),buffer.end());
        modify_bst(root,buffer);
            
    }
};