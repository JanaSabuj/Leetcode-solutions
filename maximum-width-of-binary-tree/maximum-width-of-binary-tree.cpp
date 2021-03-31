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
    unordered_map<unsigned long long int,unsigned long long int> minw, maxw;
public:
    void dfs(TreeNode* root, unsigned long long int ht, unsigned long long int w){        
        // base
        if(root == NULL)
            return;
        
        // main
        if(minw.find(ht) == minw.end()){
            minw[ht] = w;
            maxw[ht] = w;
        }else{
            minw[ht] = min(minw[ht], w);
            maxw[ht] = max(maxw[ht], w);
        }
                        
        dfs(root->left, ht + 1, 2L * w);
        dfs(root->right, ht + 1, 2L * w + 1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root,0, 1);
        unsigned long long int ans = 0;
        for(auto x: minw){
            ans = max(ans, maxw[x.first] - minw[x.first] + 1);
        }
        
        return ans;
    }
};