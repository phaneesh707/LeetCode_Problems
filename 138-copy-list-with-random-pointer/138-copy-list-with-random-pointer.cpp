/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    
    Node* create_node(int key){
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->val = key;
        temp->next = temp->random = NULL;
        return temp;
    }
    
    
    
    Node* copyRandomList(Node* head) {
        Node* pres = head;
        Node* head1 = NULL;
        Node* pres1=NULL;
        Node* pres2=NULL;
        //creating the linked list ,random of all pointing to null
        while(pres!=NULL){
            Node* temp = create_node(pres->val);
            if(head1==NULL){   
               head1=temp;
                pres1=temp;
            }  
            else{
                pres1->next=temp;
                pres1=pres1->next;
            }
            pres=pres->next;    
        }
        
        vector<int> s;
        int count=0;
        pres2=head;
        pres1=head;
        while(pres1!=NULL){
            if(pres1->random==NULL)
                s.push_back(-1);
            else{
                while(pres2 != pres1->random){
                    count++;
                    pres2=pres2->next;
                }
                s.push_back(count);
                pres2=head;
            }
            count=0;
            pres1=pres1->next;
        }
    
        cout<<"\n"<<s.size();
        pres1=head1;
        pres2=head1;
        for(auto it = s.begin();it!=s.end();it++){
            count=*it;
            if(*it!=-1){
                while(count--)
                    pres2=pres2->next;
                pres1->random = pres2;
            }
            pres1=pres1->next;
            pres2=head1;
            
        }
        
        
        
        
        
        
        
        
        
        
        
        
        //establishing random-links
//         Node* pres2=head1;
//         pres1=head1;
//         pres=head;
//         int key;
//         while(pres1!=NULL){
//             if(pres->random != NULL){
//                 key=pres->random->val;
//                 while(key!=pres2->val)
//                     pres2=pres2->next;
//                 pres1->random = pres2;
                
//             }
            
//             pres2=head1;
//             pres1=pres1->next;
//             pres=pres->next;
                
//         }
        
        return head1;
           
    }
};