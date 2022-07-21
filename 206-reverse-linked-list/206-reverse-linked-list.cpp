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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        if(head->next->next == NULL){
            ListNode* pres = head->next;
            pres->next = head;
            head->next = NULL;
            head = pres;
            return head;
        }
        ListNode* prev = head;
        ListNode* pres = head->next;
        ListNode* forw = pres->next;
        prev->next = NULL;
        while(forw!=NULL){
            pres->next = prev;
            prev=pres;
            pres = forw;
            forw=forw->next;
            
        }
        
        pres->next = prev;
        head = pres;
        return pres;
        
    }
};