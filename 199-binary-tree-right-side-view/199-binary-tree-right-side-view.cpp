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
        // if(root->left) temp.push(root->left);
        // if(root->right) temp.push(root->right);
        TreeNode* pres;
        while(!q.empty()){
            pres = q.front();
            q.pop();
            
            if(pres->left)
                temp.push(pres->left);
            if(pres->right)
                temp.push(pres->right);
            // cout<<pres->val<<endl;
            if(q.empty()){
                TreeNode* t = NULL;
                while(!temp.empty()){
                    t = temp.front();
                    temp.pop();
                    q.push(t);
                    cout<<t->val<<" ";
                }
                cout<<endl;
                if(t)
                    a.push_back(t->val);
            }
            
        }
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> a;
        dfs(root,a);
        return a;
    }
};