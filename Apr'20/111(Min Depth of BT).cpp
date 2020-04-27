/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef TreeNode node;
class Solution {
public:
    int minDepth(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        queue<node*> q;
        q.push(root);
        
        int level = 0;
        
        while(!q.empty()){
            int sz = q.size();
            level++;
            
            while(sz--){
                node* x = q.front();
                q.pop();
                
                if(x->left == NULL and x->right == NULL)
                    return level;
                
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }                        
        }
            
        return level;// code never reaches here. just to satisfy the compiler
        
    }
};

///////////////////

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL and root->right == NULL)
            return 1;
        if(root->left and root->right == NULL)
            return 1 + minDepth(root->left);
        if(root->right and root->left == NULL)
            return 1 + minDepth(root->right);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
