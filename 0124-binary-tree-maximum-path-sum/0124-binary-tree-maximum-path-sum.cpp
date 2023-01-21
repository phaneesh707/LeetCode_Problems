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
    
   int recur(TreeNode* root,int& maxi){
       if(root == NULL)
           return 0;
       int lsum = recur(root->left,maxi);
       int rsum = recur(root->right,maxi);
       int sum = root->val;
       if(lsum>=0) sum+=lsum;
       else lsum = 0;
       if(rsum>=0) sum+=rsum;
       else rsum = 0;
       maxi = max(maxi,sum);
       
       return root->val + max(lsum,rsum);
   }
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        recur(root,maxi);
        return maxi;
    }
};