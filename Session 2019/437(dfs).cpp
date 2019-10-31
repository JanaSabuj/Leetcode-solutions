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
    
    int helper(node* root, int sum){
        if(root == NULL)
            return 0;
        
        int cnt = 0;
        if(root->val == sum)
            cnt++;
        return cnt + helper(root->left,sum - root->val) +  helper(root->right,sum - root->val);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        
        return helper(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
    }
};