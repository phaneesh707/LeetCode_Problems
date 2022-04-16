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
    //time complexity - O(N)
    //to calculate total sum
    void inorder(TreeNode* root,int& sum){
        if(!root) return;
        inorder(root->left,sum);
        sum+=root->val;
        inorder(root->right,sum);
    }
    
    void update(TreeNode* root,int& sum,int& prev){
        if(!root) return;
        update(root->left,sum,prev);
        
        
        //prev holds previous elements sum ;
        //sum holds the sum of all elem >= root->val;
        prev = root->val;
        root->val=sum;
        sum-=prev;
        update(root->right,sum,prev);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum=0,prev=0;
        inorder(root,sum);
        update(root,sum,prev);
        return root;
    }
};