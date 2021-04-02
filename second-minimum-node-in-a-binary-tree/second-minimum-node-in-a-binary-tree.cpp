/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        
        if(root->left == NULL)
            return -1;
        
        int l = root->left->val == root->val ? findSecondMinimumValue(root->left) : root->left->val;
        int r = root->right->val == root->val ? findSecondMinimumValue(root->right) : root->right->val;
        
        if(l == -1 || r == -1)
            return max(l, r);
        return min(l,r);
    }
};