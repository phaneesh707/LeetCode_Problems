/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define maxi 100000
int getMinimumDifference(struct TreeNode* root){
    struct TreeNode* pres = root;
    struct TreeNode* prev = NULL;
    struct TreeNode* s[101];
    int top=-1;
    int a[maxi];
    int i=0,sub=maxi,prevVal=maxi;
    
    do{
        while(pres!=NULL){
            // prev=pres;
            s[++top]=pres;
            pres = pres->left;
        }
        pres = s[top--];
        if(abs(pres->val - prevVal)<sub)
            sub = abs(pres->val - prevVal);
        prevVal = pres->val;
        pres=pres->right;
    }while(top!=-1 || pres!=NULL);

    
    
    return sub;
    
}