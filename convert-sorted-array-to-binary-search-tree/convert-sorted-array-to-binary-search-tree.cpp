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
typedef struct TreeNode node;
class Solution {
public:
    node* solve(int i, int j, vector<int>& nums){
        if(i > j)
            return NULL;
        
        int mid = (i + j)/2;        
        node* root = new node(nums[mid]);
        
        root->left = solve(i, mid-1,nums);
        root->right = solve(mid+1,j,nums);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        
        return solve(i, j, nums);
    }
};