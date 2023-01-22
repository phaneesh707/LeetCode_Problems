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
    int height(TreeNode* root){
        if(root == NULL) 
            return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    
    void bfs(TreeNode* root,vector<vector<int>>& res){
        if(root == NULL) return;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            pair<TreeNode*,int> temp = q.front();
            res[temp.second].push_back(temp.first->val);
            q.pop();
            if(temp.first->left)
                q.push({temp.first->left,temp.second+1});
            if(temp.first->right)
                q.push({temp.first->right,temp.second+1});
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> res(h);
        bfs(root,res);
        for(int i=0;i<h;i++){
            if(i%2==1)
                reverse(res[i].begin(),res[i].end());
        }
        return res;
    }
};