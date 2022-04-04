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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* pres = head,*prev,*front;
        int count=1;
        while(pres!=NULL){
            
            if(count==k)
                prev=pres;
            pres=pres->next;
            count+=1;
        }
        count--;
        pres=head;
        while(pres!=NULL){
            
            if(count==k)
                front = pres;
            pres=pres->next;
            count--;
        }
        if(front!=prev){
            int dummy = front->val;
            front->val = prev->val;
            prev->val = dummy;
            
        }
        
        
        
        return head;
    }
};