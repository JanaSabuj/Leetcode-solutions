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
    bool isPalindrome(ListNode* head) {
        node* slow = head, *runner = head;
        // node* runner = head;
        stack<int> s;
        
        while(runner != NULL and runner->next != NULL){
            s.push(slow->val);
            slow = slow->next;
            runner = runner->next->next;
        }
        
        if(runner != NULL)
            slow = slow->next;
        
        while(slow != NULL){
            if(s.top() != slow->val)
                return false;
            slow = slow->next;
            s.pop();
        }
        
        return true;
    }
};
----------------------------------------------------------------------------------------------
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
    node* reverse(node* head){
        if(head == NULL or head->next == NULL)
            return head;
        
        node* tail = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return tail;
    }
    bool isPalindrome(ListNode* head) {
        node* slow = head, *runner = head;
        
        while(runner != NULL and runner->next != NULL){
            slow = slow->next;
            runner = runner->next->next;            
        }
        
        node* tail = NULL;
        node* end = NULL;
        if(runner != NULL){
            tail = reverse(slow->next);
            end = slow;
        }else{
            tail = reverse(slow);
            end = slow;
        }
        
        node* later = tail;
        node* mouth = head;
        while(tail != NULL){
            if(mouth->val != tail->val)
                return false;
            mouth = mouth->next;
            tail = tail->next;
        }
        
      
        return true;
        
        
    }
};
