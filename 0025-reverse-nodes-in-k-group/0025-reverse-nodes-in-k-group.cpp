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
        
        // using stack
        if(head == NULL || head->next == NULL)
            return head;
        
        stack<ListNode*> s;
        ListNode* dummy = new ListNode();
        ListNode *pres = head,*temp = dummy;
        int i=0;
        while(pres){
            s.push(pres);
            i++;
            pres = pres->next;
            if(i%k==0){
                while(!s.empty()){
                    ListNode* ptr = s.top();
                    ptr->next = NULL;
                    temp->next = ptr;
                    temp = ptr;
                    s.pop();
                }
            }
        }
        
        while(s.size()>1){
            s.pop();
        }
        if(!s.empty()){
            temp->next = s.top();
            s.pop();   
        }
        
        
        return dummy->next;
        
    }
};