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
    
    void bfs(TreeNode* root,vector<vector<int>>& res){
        if(root == NULL) return;
        
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int sz = q.size();
            vector<int> a(sz);
            for(int i=0;i<sz;i++){
                TreeNode* temp = q.front();
                q.pop();
                
                int idx = flag?i:sz-i-1;
                a[idx] = temp->val;
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                
            }
            flag = !flag;
            res.push_back(a);
            
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bfs(root,res);
        return res;
    }
};