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
#define inf (1 << 20)
map<pair<TreeNode*, pair<int,int>>, int> dp;

class Solution {
public:
    int solve(TreeNode* root, int placeCam, int parCam){
        // base
        if(root == NULL){
            if(placeCam)
                return inf;
            else
                return 0;    
        }
        
        if(root->left == NULL and root->right == NULL){
            if(placeCam)
                return 1;
            
            if(parCam)
                return 0;
            else
                return inf;
        }
        
        // dp
        if(dp.find({root, {placeCam, parCam}}) != dp.end())
            return dp[{root, {placeCam, parCam}}];
        
        
        // main
        if(placeCam){
            return dp[{root, {placeCam, parCam}}] = 1 + min(solve(root->left, 0, 1), solve(root->left, 1, 1)) + min(solve(root->right, 0, 1), solve(root->right, 1, 1));                         
        }else {
            if(parCam){
                return dp[{root, {placeCam, parCam}}] = min(solve(root->left, 0, 0), solve(root->left, 1, 0)) + min(solve(root->right, 0, 0), solve(root->right, 1, 0));
            }else{
                int op1 = solve(root->left, 1, 0) + min(solve(root->right, 0, 0), solve(root->right, 1, 0));
                
                int op2 = solve(root->right, 1, 0) + min(solve(root->left, 0, 0), solve(root->left, 1, 0));
                return dp[{root, {placeCam, parCam}}] = min( op1, op2);
            }
        }                
    }
    
    int minCameraCover(TreeNode* root) {
        dp.clear();
        return min(solve(root, 0, 0), solve(root, 1, 0));        
    }
};
