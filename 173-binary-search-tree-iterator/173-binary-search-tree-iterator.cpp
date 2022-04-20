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
class BSTIterator {
public:
    vector<int> bst;
    int k;
    void inorder(TreeNode* root,vector<int>& bst){
        if(root){
            inorder(root->left,bst);
            bst.push_back(root->val);
            inorder(root->right,bst);
        }
    }
    
    BSTIterator(TreeNode* root) {
        k=0;
        inorder(root,bst);       
    }
    
    int next(){
        if(k<bst.size())
            return bst[k++];
        return -1;
    }
    
    bool hasNext() {
        if(k<bst.size())
            return true;   
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */