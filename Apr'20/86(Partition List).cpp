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
    ListNode* partition(ListNode* head, int x) {
        node* before = new node(0);
        node* after = new node(0);
        
        node* b_head = before;
        node* a_head = after;
        
        while(head != NULL){
            if(head->val < x){
                before->next = new node(head->val);
                before = before->next;
            }else{
                after->next = new node(head->val);
                after = after->next;
            }
            
            head = head->next;
        }
        
        before->next = a_head->next;
        
        return b_head->next;
    }
};
