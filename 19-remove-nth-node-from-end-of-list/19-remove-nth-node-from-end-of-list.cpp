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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        node* dummy = new node(0);
        dummy->next = head;

        node* right = head;
        node* left = head;
        node* prev = dummy;

        // [-------------------------------]
        //      n                L-n             
        // [-------------|-----------------]
        //      L-n         |     n

        int cnt = n;
        while(right != NULL and cnt--) {
            // right traverses n steps
            right = right->next; 
        }

        while(right != NULL) {
            // right traverses (L-n) steps
            right = right->next;
            prev = left;
            left = left->next;
        }

        prev->next = left->next;

        return dummy->next;
    }
};