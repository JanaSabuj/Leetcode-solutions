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
    
    void dfs(node* root, int depth, vector<int> &req){
        
        if(root == NULL)
            return ;
        
        if(root->left == NULL and root->right == NULL){
            depth = depth + 1;
            req.push_back(depth);
        }else{
            depth +=1;
            dfs(root->left,depth,req);
            dfs(root->right,depth,req);
        }
            
    }
    
    int minDepth(TreeNode* root) {
        vector<int> req;
        int depth=0;
        
        dfs(root,depth,req);
        
        if(root == NULL)
            return 0;
        
        return *min_element(req.begin(), req.end());
    }
};