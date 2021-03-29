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
    string str;
public:
    void dfs(TreeNode* t){
        if(t == NULL)
            return;
        
        str += to_string(t->val);
        
        if(t->left or t->right){
            str += "(";
            dfs(t->left);
            str += ")";
        }
        
        if(t->right){
            str += "(";
            dfs(t->right);
            str += ")";
        }
        
    }
    string tree2str(TreeNode* t) {
        dfs(t);
        return str;
    }
};