/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void nextConnect(vector<Node*>& v,Node* root,int height){
        if(root!=NULL){
            nextConnect(v,root->right,height+1);
            root->next = v[height];
            v[height] = root;
            cout<<root->val<<" "<<height<<endl;
            nextConnect(v,root->left,height+1);
        }
    }

    Node* connect(Node* root) {
        // int height = calcHeight(root);
        vector<Node*> v(6000,NULL);
        nextConnect(v,root,0);
        return root;
    }
};