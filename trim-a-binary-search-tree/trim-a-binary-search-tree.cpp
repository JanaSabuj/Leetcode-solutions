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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // base
        if(root == NULL)
            return NULL;
        
        // main
        int curr = root->val;
        if(curr >= low and curr <= high){
            // valid
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
        
        if(curr < low){
            return trimBST(root->right, low, high);
        }
        
        if(curr > high){
            return trimBST(root->left, low, high);
        }
        
        return root;
    }
};
