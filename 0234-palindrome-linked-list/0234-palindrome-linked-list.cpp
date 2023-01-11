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
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
            return true;
        
        ListNode *slow = head,*fast = head,*prev = NULL,*forw = NULL;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        // reverse the ll from middle 
        prev->next = NULL;
        while(slow->next!=NULL){
            forw = slow->next;
            slow->next = prev;
            prev = slow;
            slow = forw;
        }
        slow->next = prev;
        forw = head;

            
        // check for pal  
        while(forw){
            if(forw->val != slow->val)
                return false;
            forw=forw->next;
            slow=slow->next;
        }
        return true;
    }
};