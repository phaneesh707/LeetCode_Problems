/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


    //delete funciton 
    struct TreeNode* del_node(struct TreeNode *r,int ele)
{
	struct TreeNode *temp;struct TreeNode *p;
	if(r==NULL) return r;
	else if(ele<r->val)
		r->left=del_node(r->left,ele);	
	else if(ele>r->val)
		r->right=del_node(r->right,ele);
	else
	{
        if(r->right==NULL && r->left==NULL){
            free(r);
            return NULL;
            
        }else if(r->left==NULL){
			temp=r->right;
			free(r);
			return temp;
			
		}else if(r->right==NULL){
			temp=r->left;
			free(r);
			return temp;
		}else{
			p=r->right;
			while(p->left!=NULL) //inorder successor
			{
				p=p->left;
			}
			r->val=p->val;
			r->right=del_node(r->right,p->val);
		}
	}
	return r;
}
    

    //inorder traveral to put all the unwanted items in item list
    void inorder(struct TreeNode* root,int low,int high,int* item,int* k){
        // static int k=0;
        if(root == NULL)
            return;
        inorder(root->left,low,high,item,k);
        if(root->val < low || root->val > high)
            item[(*k)++]=root->val;
        inorder(root->right,low,high,item,k);
    }
    


struct TreeNode* trimBST(struct TreeNode* root, int low, int high){
        int item[10000];
        int k =0 ;
        int count =0;
        for(int i=0;i<10000;i++)
            item[i]=-1;
    
        inorder(root,low,high,item,&count);
    
        //deleting one by one 
        while(item[k]!=-1){
            root = del_node(root,item[k]);
            k++;
        }
        return root;
}