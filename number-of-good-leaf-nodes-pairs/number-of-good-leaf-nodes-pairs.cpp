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
    int cnt = 0;
    vector<int> lr(TreeNode* root, int d){
        if(root == NULL)
            return {};
        
        if(root->left == NULL and root->right == NULL)
            return {1};
        
        auto l = lr(root->left, d);
        auto r = lr(root->right, d);
        
        for(auto a: l){
            for(auto b: r){
                if(a + b <= d)
                    cnt++;
            }
        }        
        
        vector<int> ret;
        for(auto a: l){
            if(a + 1 < d)
                ret.push_back(a + 1);
        }        
        
        for(auto b: r){
            if(b + 1 < d)
                ret.push_back(b + 1);
        }        
        
        return ret;
    }
    
    int countPairs(TreeNode* root, int distance) {
        lr(root, distance);
        return cnt;
    }
};
