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
    ListNode* reverseList(ListNode* head) {
       if(head == NULL or head->next == NULL)
           return head;
        node* tail = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return tail;
    }
};
