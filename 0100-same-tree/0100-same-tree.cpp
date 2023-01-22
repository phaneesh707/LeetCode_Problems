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
    
    void inorder(TreeNode* p,TreeNode* q,bool& res){
        if(p == NULL && q == NULL)
            return;
        else if(p == NULL || q == NULL){
            res = false;
            return;
        }
        
        inorder(p->left,q->left,res);
        if(p->val!=q->val) res = false;
        inorder(p->right,q->right,res);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res = true;
        inorder(p,q,res);
        return res;
    }
};