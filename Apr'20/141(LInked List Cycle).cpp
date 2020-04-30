/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef ListNode node;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        node* p , *q = head;
        
        while(p and q and q->next){
            p = p->next;
            q = q->next->next;
            
            if(p == q)
                return true;
        }
        
        return false;
    }
};
