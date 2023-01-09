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
    void deleteNode(ListNode* node) {
        ListNode* pres = node->next;
        ListNode* temp = node;
        while(pres->next!=NULL){
            temp->val = pres->val;
            temp = pres;
            pres = pres->next;
        }
        
        temp->val = pres->val;
        temp->next = NULL;
        delete(pres);
    }
};