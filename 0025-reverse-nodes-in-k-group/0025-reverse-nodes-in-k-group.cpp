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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* dummy = new ListNode();
        ListNode* pres = head,*prev = NULL ,*forw = NULL,*temp = dummy;
        int count = 0,i=0,flag = 0;
        while(pres){
            pres = pres->next;
            count++;
        }
        pres = head;
        count = count - count%k;
        while(pres && i<count){
            forw = pres->next;
            pres->next = prev;
            prev = pres;
            pres = forw;
            i++;
            if(i%k==0){
                temp->next = prev;
                while(temp->next){
                    temp = temp->next;
                }
                //##
                prev = NULL;
                
            }
        }
        temp->next = pres;
        return dummy->next;
    }
};