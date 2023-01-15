/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        
        Node *pres = head,*temp;
        // 1.insert the duplicate nodes
        while(pres){
            Node *node = new Node(pres->val);
            node->next = pres->next;
            pres->next = node;
            pres = node->next;
        }
        
        // 2. connect the random ptrs
        pres = head;
        while(pres){
            if(pres->random!=NULL){
                pres->next->random = pres->random->next;
            }   
            pres = pres->next->next;
        }
        
        // 3.extract the originl and duplicate list;
        Node* dummy = new Node(0);
        pres = head;
        temp = dummy;
        temp->next = head->next;
        temp = temp->next;
        while(pres){
            pres->next = pres->next->next;
            pres = pres->next;
            if(temp->next)
                temp->next = temp->next->next;
            temp = temp->next;
    
        }
        
        return dummy->next;
        
        
        
        
    }
};