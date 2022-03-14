struct ListNode* del(struct ListNode* head,struct ListNode* ele){
    if(head==NULL) return head;
    else{
        struct ListNode* pres = head;
        struct ListNode* prev = NULL;
        while(pres!=ele){
            prev=pres;
            pres=pres->next;
        }
        if(prev==NULL)
            head = pres->next;
        else{
            prev->next=pres->next;
            free(pres);
            pres=NULL;
        }
    }
    return head;
}

struct ListNode* inst(struct ListNode* head,int valu,struct ListNode* nxt){
    
  
        struct ListNode* pres=head;
        struct ListNode* prev=NULL;

        while(pres!=NULL && pres->val<valu && nxt!=pres){
            prev=pres;
            pres=pres->next;

        }
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = valu;
        if(prev==NULL){
            temp->next=head;
            head=temp;

        }else{
            temp->next=pres;
            prev->next=temp;

        }
        return head;
}

struct ListNode* insertionSortList(struct ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    else{
        struct ListNode* pres = head->next;
        struct ListNode* presNext = pres->next;

        while(pres!=NULL){
            int cur = pres->val;
            head = del(head,pres);
            head = inst(head,cur,presNext);
            if(presNext==NULL) break;
          pres=presNext;
            presNext=presNext->next; 

        }
        return head;
    }
}
