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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return head;
        
        node* curr = head;
        while(curr->next != NULL){
            if(curr->val == curr->next->val){
                node* t = curr->next;
                curr->next = t->next;
                // curr = curr->next;
                delete(t);
            }else{
                curr = curr->next;
            }
        }
        
        return head;
    }
};