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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        map<int,int> m;
        dfs(root,m,0);
        for(auto it=m.begin();it!=m.end();it++)
            res.push_back(it->second);
        return res;
    }
    
    void dfs(TreeNode* root,map<int,int>& m,int x){
        if(root){
            dfs(root->left,m,x+1);
            m[x] = root->val;
            dfs(root->right,m,x+1);
        }
    }
    
};