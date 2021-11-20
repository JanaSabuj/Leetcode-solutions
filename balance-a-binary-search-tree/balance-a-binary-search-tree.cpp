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
typedef TreeNode node;
class Solution {
public:
    vector<int> arr;
    void inorder(node* root) {
        if(root == NULL)
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    
    node* go(int low, int high) {
        if(low > high)
            return NULL;
        
        int mid = (low + high) / 2;
        node* root = new node(arr[mid]);
        root->left = go(low, mid - 1);
        root->right = go(mid + 1, high);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int low = 0, high = arr.size() - 1;
        return go(low, high);
    }
};