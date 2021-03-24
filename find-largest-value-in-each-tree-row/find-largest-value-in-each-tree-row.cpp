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
    map<int,int> mp;    
public:
    void dfs(TreeNode* root, int ht){
        if(root == NULL)
            return;
        // current
        if(mp.find(ht) == mp.end())
            mp[ht] = root->val;
        else
            mp[ht] = max(mp[ht], root->val);
        dfs(root->left, ht + 1);
        dfs(root->right, ht + 1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        vector<int> ans;
        
        for(auto x: mp){
            ans.push_back(x.second);         
        }
        
        return ans;
    }
};