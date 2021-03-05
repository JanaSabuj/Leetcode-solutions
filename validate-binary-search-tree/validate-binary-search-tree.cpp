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
    bool isValidBST(TreeNode* root, long minval = LLONG_MIN, long maxval = LLONG_MAX) {
        if(root == NULL)
            return true;
        return isValidBST(root->left, minval, root->val) and (minval < root->val and root->val < maxval) and isValidBST(root->right, root->val, maxval);
    }
};