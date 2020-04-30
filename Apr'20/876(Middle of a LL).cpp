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
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        node* p = head;
        while(p != NULL){
            len++;
            p = p->next;
        }
        
        int middle = len/2 + 1;
        
        p = head;
        int cnt = 0;
        while(p != NULL){
            cnt++;            
            if(cnt == (middle))
                return p;
            p = p->next;
        }
        
        return NULL;
    }
};

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
    ListNode* middleNode(ListNode* head) {
        node* p = head, *q = head;
        
        while(q and q->next){
            p = p->next;
            q = q->next->next;            
        }
        
        return p;
    }
};
