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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        node* a = headA;
        node* b = headB;
        
        node* lasta, *lastb;
        while(a != b){
            a = (a == NULL ? headB  : a->next);                     
            b = (b == NULL ? headA  : b->next);             
        }
        
        return a;
        
    }
};
