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
    void inorder(TreeNode* root,vector<int>& buffer,int flag){
        if(root!=NULL){
            inorder(root->left,buffer,flag);
            if(flag==0)
                buffer.push_back(root->val);
            else
                 root->val = buffer[i++];
            inorder(root->right,buffer,flag);
        }
    }
    
  
    
    
    void recoverTree(TreeNode* root) {
        vector<int> buffer;
        inorder(root,buffer,0);
        sort(buffer.begin(),buffer.end());
        inorder(root,buffer,1);
            
    }
};