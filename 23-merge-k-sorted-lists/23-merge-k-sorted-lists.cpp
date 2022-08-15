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
typedef pair<int, ListNode*> pil;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pil, vector<pil>, greater<pil>> pq;// min-heap
        int k = lists.size();

        for (int i = 0; i < k; i++) {
            if(lists[i] != NULL)
                pq.push({lists[i]->val, lists[i]});
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            // dummy updt
            curr->next = top.second;
            curr = curr->next;

            // pq updt
            if (top.second->next != NULL)
                pq.push({top.second->next->val, top.second->next});
        }

        return dummy->next;
    }
};