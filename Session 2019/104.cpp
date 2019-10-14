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
    
    void dfs(node* root, int depth, vector<int> &leafDepth){
        
        if(root==NULL)
            return;
        
        if(root->left == NULL and root->right == NULL){
            depth++;
            leafDepth.push_back(depth);
        }
        else{
            depth++;
            dfs(root->left,depth,leafDepth);
            dfs(root->right,depth,leafDepth);
        }
        
    }
    
    int maxDepth(TreeNode* root) {
        
        vector<int> leafDepth;
        int depth=0;
        if(root==NULL) return 0;
        dfs(root,depth,leafDepth);
        
        return *max_element(leafDepth.begin(), leafDepth.end());
        
    }
};