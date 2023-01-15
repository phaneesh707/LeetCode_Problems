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
        Node* dummy = new Node(0);
        
        Node *pres = head,*temp = dummy,*ptr1,*ptr2;
        while(pres){
            Node* node = new Node(pres->val);
            temp->next = node;
            temp = node;
            pres = pres->next;
            
        }
        
        pres = head;
        temp = dummy->next;
        
        while(pres){
            ptr1 = head;
            ptr2 = dummy->next;
            if(pres->random!=NULL){
                while(pres->random!=ptr1){
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
                temp->random = ptr2;
            }
            temp = temp->next;
            pres = pres->next;
            
        }
        
        
        return dummy->next;
        
    }
};