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
    
    bool isSymmetric(node* left, node* right){
        if(left == NULL or right == NULL)
            return left==right;
        
        if(left->val != right->val)
            return false;
        
        return isSymmetric(left->left,right->right) and isSymmetric(left->right,right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        return isSymmetric(root->left,root->right);
    }
};