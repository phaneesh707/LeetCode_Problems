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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
        TreeNode* temp = new TreeNode(val);
        temp->left = temp->right = NULL;
        TreeNode* prev=NULL;
        TreeNode* pres = root;
        if(root == NULL){
            root = temp;
            return root;
        }

        while(pres!=NULL){
            cout<<pres->val<<endl;
            prev = pres;
            if(val > pres->val)
                pres = pres->right;
            else 
                pres = pres->left;
        }
        cout<<prev->val;
        cout<<"out";
        if(prev->val < val)
            prev->right = temp;
        else 
            prev->left = temp;
        // cout<<root->val;
        pres = root;
        return pres;
    }
};