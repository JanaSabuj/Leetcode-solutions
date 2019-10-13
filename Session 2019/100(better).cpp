/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef struct TreeNode node;
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL)
            return true;
        if(p!=NULL and q!=NULL){
            if(p->val == q->val and isSameTree(p->left,q->left) and isSameTree(p->right,q->right))
                return true;
        }
        
        return false;
    }
};