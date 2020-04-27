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
