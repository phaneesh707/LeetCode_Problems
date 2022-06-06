/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    //intution - calcu the differnce between the len of 2 linkend list and place the ptr of the longer list by the differnce so that once they traverse they meet at intersection.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        if(a==NULL || b==NULL) return NULL;
        while(a!=b){
           if(a==NULL) a = headB;
            else a = a->next;
            
            if(b==NULL) b = headA;
            else b = b->next;
            
        }
        return a;
    }
};