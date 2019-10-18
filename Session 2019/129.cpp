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
    
    void dfs(node* root, string ans, vector<string> &req){
    
        if(root==NULL)
            return ;
        
        
        ans = ans + to_string(root->val);
        
        if(root->left == NULL and root->right == NULL)
        { 
            req.push_back(ans);
        }
        
        dfs(root->left, ans, req);
        dfs(root->right, ans, req);
        
    }
    
    int sumNumbers(TreeNode* root) {
        
        string ans="";
        vector<string> req;
        dfs(root, ans, req);
        
     int sum=0;
        
        for(auto x: req){
            sum +=(stoi(x)) ;
        }
        
        return sum;
    }
};