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
    ListNode* addTwoNumbers(ListNode* p, ListNode* q) {
        ListNode* head = new ListNode(0);
        ListNode* dummy = head;
        
        int c = 0;
        int d = 0;
        while(p != NULL or q != NULL){
            int sum = (p != NULL ? p->val : 0) + (q != NULL ? q->val : 0) + c;
            d = sum % 10;
            c = sum / 10;
            
            head->next = new ListNode(d);
            p = (p != NULL ? p->next : NULL);
            q = (q != NULL ? q->next: NULL);
            head = head->next;
        }
        
        if(c)
            head->next = new ListNode(1);
        
        return dummy->next;
    }
};