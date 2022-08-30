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
        int leng = 0;
        ListNode* pres = head;
        while(pres){
            leng++;
            pres=pres->next;
        }
        
        stack<int> s;
        pres = head;
        if(leng%2==0){
            for(int i=0;i<leng/2;i++){
                s.push(pres->val);
                pres = pres->next;
            }
            for(int i=leng/2;i<leng;i++){
                if(!s.empty() && s.top() == pres->val)
                    s.pop();
                pres=pres->next;
            }
                
        }else{
            for(int i=0;i<leng/2;i++){
                s.push(pres->val);
                pres = pres->next;
            }
            pres=pres->next;
            for(int i=leng/2;i<leng-1;i++){
                if(!s.empty() && s.top() == pres->val)
                    s.pop();
                pres=pres->next;
            }
        }
        
        return s.empty();
        
    }
};