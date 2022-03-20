/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



void sumBst(struct TreeNode* root,int low ,int high,int* sum){
    // static int sum = 0;
    if(root!=NULL){
        if(root->val<=high && root->val>=low)
            (*sum)+=root->val;
        sumBst(root->left,low,high,sum);
        sumBst(root->right,low,high,sum);
        
    }
}

int rangeSumBST(struct TreeNode* root, int low, int high){
    
    int sum = 0;
    sumBst(root,low,high,&sum);
    
    return sum;

}