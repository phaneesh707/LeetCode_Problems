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
    
    void bfs(TreeNode* root,vector<vector<int>>& a){
        if(!root) return;
        
        queue<TreeNode*> q;
        queue<TreeNode*> q1;
        q.push(root);
        vector<int> pres;
        pres.push_back(root->val);
        a.push_back(pres);
        
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->left) q1.push(temp->left);
            if(temp->right) q1.push(temp->right);
            
            if(q.empty()){
                vector<int> dummy;
                while(!q1.empty()){
                    q.push(q1.front());
                    dummy.push_back(q1.front()->val);
                    q1.pop();
                }
                if(dummy.size()>0)
                    a.push_back(dummy);
                
            }
            
        }
    }
    
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> a;
        bfs(root,a);
        return a;
    }
};