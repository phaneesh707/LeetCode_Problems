/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy,*p=list1,*q=list2;
        while(p!=NULL && q!=NULL){
            if(p->val <= q->val){
                temp->next = p;
                temp = p;
                p = p->next;
            }else if(p->val > q->val){
                temp->next = q;
                temp = q;
                q = q->next;
            }
        }
        
        while(p!=NULL){
            temp->next = p;
            temp = p;
            p = p->next;
        }
        
        while(q!=NULL){
            temp->next = q;
            temp = q;
            q = q->next;
        }
        
        return dummy->next;
    }
};