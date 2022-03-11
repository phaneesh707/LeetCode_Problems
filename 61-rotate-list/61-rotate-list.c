/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head!=NULL && head->next!=NULL){
    struct ListNode* pres = head;
    int count=1;
    
    while(pres->next!=NULL){
        pres=pres->next;
        count++;
    }
    pres->next=head;
    pres=head;
    k=count-(k%count);
    if(k){
       while(--k){
            pres=pres->next;
        }
        head=pres->next;
        pres->next = NULL;
     
        }  
    }
    return head;
    
}