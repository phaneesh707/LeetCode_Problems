class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        else{
        
            int count=0;

            ListNode* pres=head;
            while(pres!=NULL){
                count++;
                pres=pres->next;
            }
            pres=head->next;
            ListNode* prev=head;
            ListNode*prev_before=NULL;
            if(count==2){

                prev->next=pres->next;
                pres->next=prev;
                head=pres;
            }
            else if(count%2==0 && count!=2){//even
                while(pres!=NULL){
                    if(prev_before!=NULL)
                        prev_before->next = pres; 
                    prev->next=pres->next;
                    pres->next=prev;
                    
                    if(head==prev)
                        head=pres;
                    if(prev->next==NULL){
                        break;
                    }
                    prev_before=prev;
                    pres=prev->next->next;
                    prev=prev->next;
                    
                }
            }else{
                    while(prev->next!=NULL && prev->next->next!=NULL && pres!=NULL){
                    if(prev_before!=NULL)
                        prev_before->next = pres; 
                    prev->next=pres->next;
                    pres->next=prev;
                    if(head==prev)
                        head=pres;
                    if(prev->next->next==NULL){
                        break;
                    }
                    prev_before=prev;
                    pres=prev->next->next;
                    prev=prev->next;
                        

                    }


                
                }
                return head;
    
            }
    }
};

