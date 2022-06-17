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
    

//     int count = 0;
//     void PostOrder(TreeNode* root){
//         if(root){
//             PostOrder(root->left);
//             PostOrder(root->right);
//             if(root->left == NULL && root->right == NULL)
//                 root->val = 1;
//             else if((root->left && root->left->val == 2) || (root->right &&root->right->val == 2))
//                 root->val = 1;
//             else if((root->left && root->left->val == 2) || (root->right &&root->right->val == 2))
//                 root->val = 1;
//             else if((root->left && root->left->val == 1) || (root->right && root->right->val == 1)){
//                 root->val = 2;
//                 count++;
//             }
//         }
//     }
    
    #define HAS_CAMERA 2
    #define NO_CAMERA 0
    #define NO_NEED 1
    
    int count = 0;
    int PostOrder(TreeNode* root){
        if(root == NULL)
            return NO_NEED;
        int l = PostOrder(root->left);
        int r = PostOrder(root->right);
        
        if(l == NO_CAMERA || r == NO_CAMERA){
            count++;
            return HAS_CAMERA;
        }else if(l == HAS_CAMERA || r == HAS_CAMERA)
            return NO_NEED;
        else
            return NO_CAMERA;
    }
    
    
    int minCameraCover(TreeNode* root) {
       
        
        if(PostOrder(root)==NO_CAMERA)
            count++;
        return count;
    }
};