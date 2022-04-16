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
    void inorder(TreeNode* root,vector<int>& node){
        if(!root) return;
        inorder(root->left,node);
        node.push_back(root->val);
        inorder(root->right,node);
    }
    
    void update(TreeNode* root,vector<int> node){
        if(!root) return;
        update(root->left,node);
        int sum = 0;
        for(int i=0;i<node.size();i++){
            if(node[i]>root->val)
                sum+=node[i];
        }
        root->val+=sum;
        update(root->right,node);
    }
    
    void ino(TreeNode* root){
        if(!root) return;
        ino(root->left);
        // node.push_back(root->val);
        cout<<root->val<<endl;
        ino(root->right);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        vector<int> node;
        inorder(root,node);
        update(root,node);
        ino(root);
        return root;
    }
};