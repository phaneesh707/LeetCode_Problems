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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head!=NULL && head->next!=NULL){
            ListNode* pres = head->next;
            ListNode* prev = head;
            set<int> s;
            while(pres!=NULL){
                if(prev->val == pres->val){
                    s.insert(pres->val);
                    prev->next = pres->next;
                    delete(pres);
                    pres=prev->next;


                }else{
                    prev=pres;
                    pres=pres->next;
                }

            }
            
            pres=head;
           
            
            // for(auto it=s.begin();it!=s.end();it++){
                auto it=s.begin();
                while(pres!=NULL && it!=s.end()){
                    if(*it==pres->val && pres==head){
                        head=pres->next;
                        delete(pres);
                        pres=head;
                        it++;
                        
                    }else if(*it==pres->val){
                        prev->next=pres->next;
                        delete(pres);
                        pres=prev->next;
                        it++;
                    }else{
                        prev=pres;
                        pres=pres->next;
                    }
                    
                }
            // }
            
            
          
        
    }
          return head;
    }
};