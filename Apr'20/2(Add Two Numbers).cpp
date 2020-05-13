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
typedef struct ListNode node;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
           node* head = new node(0);
            node* orig = head;
            
        node* p = l1, *q = l2;
        int c = 0;
        
            while(p != NULL or q != NULL){
                int s = (p != NULL ? p->val : 0) + (q != NULL ? q->val: 0) + c;
                int d = s % 10;
                c = s / 10;
                
                head->next = new node(d);
                p = (p != NULL ? p->next: NULL);
                q = (q != NULL ? q->next: NULL);
                head = head->next;
            }
         
        
        if(c){
            head->next = new node(1);
        }
        
        return orig->next;
    }
};
