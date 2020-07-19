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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        int x = k;
        node* curr = head;                
            while(curr != NULL and x){
                  curr = curr->next;
                x--;
            }
        
        node* first = head;
        node* prev = NULL;
        while(curr != NULL){
            curr = curr->next;
            prev = first;
            first = first->next;
        }
        
        if(prev)
            prev->next = first->next;
        else
            return head->next;
        return head;
        
    }
};
