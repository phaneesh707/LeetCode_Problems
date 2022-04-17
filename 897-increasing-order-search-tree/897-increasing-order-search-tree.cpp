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
    
    void inorder(TreeNode* root,stack<TreeNode*>& s){
        if(root == NULL) return;
        inorder(root->left,s);
        s.push(root);
        inorder(root->right,s);
    }
    
    
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> s;
        inorder(root,s);
        // cout<<s.top()->val;
        TreeNode* pres;
        TreeNode* temp = s.top();
        temp->right = temp->left = NULL;
        s.pop();
        while(!s.empty()){
            pres = s.top();
            pres->left = NULL;
            pres->right = temp;
            temp = pres;
            s.pop();
        }
        
        return temp;
    }
};