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
    
    void dfs(TreeNode* root,vector<int>& a){
        if(root == NULL)
            return;
        a.push_back(root->val);
        queue<TreeNode*> q;
        queue<TreeNode*> temp;
        q.push(root);
        while(!q.empty()){
            TreeNode* pres = q.front();
            q.pop();
            
            if(pres->left)
                temp.push(pres->left);
            if(pres->right)
                temp.push(pres->right);
            
            if(q.empty()){
                if(!temp.empty())
                    a.push_back(temp.back()->val);
                while(!temp.empty()){
                    q.push(temp.front());
                    temp.pop();
                }
                    
            }
            
        }
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> a;
        dfs(root,a);
        return a;
    }
};