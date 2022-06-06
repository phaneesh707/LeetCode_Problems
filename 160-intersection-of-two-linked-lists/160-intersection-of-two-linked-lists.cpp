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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pres = headA;
        while(pres){
            ListNode* prev = headB;
            while(prev){
                if(pres==prev)
                    return pres;
                prev=prev->next;
            }
            pres=pres->next;
        }
        
        return NULL;
    }
};