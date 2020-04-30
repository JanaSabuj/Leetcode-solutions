/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef struct ListNode node;
class Solution {
public:
    
    node* floyd(node* head){
        node* p = head;
        node* q = head;
        
        while(p and q and q->next){
            p = p->next;
            q = q->next->next;
            
            if(p == q)
                return p;
        }
        return NULL;
    }
    
    node* start(node* head, node* meet){
        node* p = head;
        node* q = meet;
        
        while(p != q){
            p = p->next;
            q = q->next;            
        }
        
        return p;
    }
    
    ListNode *detectCycle(ListNode *head) {
        node* meet = floyd(head);
        if(!meet)
            return NULL;
        else
            return start(head, meet);
    }
};
