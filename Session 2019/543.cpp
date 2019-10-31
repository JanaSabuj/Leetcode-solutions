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
    
    int ht(node* root){
        if(root == NULL)
            return -1;
        return 1 + max(ht(root->left), ht(root->right));
    }
    
    int diameterOfBinaryTree(node* root) {
        
        if(root == NULL)
            return 0;
        
        int x = 2 + ht(root->left) + ht(root->right);
        int y = diameterOfBinaryTree(root->left);
        int z = diameterOfBinaryTree(root->right);
        
        return max(x, max(y,z)) ;
                
    }
};