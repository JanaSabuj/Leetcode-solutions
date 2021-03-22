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
    vector<int> res;
    int mx = 0;
    int precursor = -1;
    int cnt = 0;
public:
    
    void inorder(node* root){
        if(root == NULL)
            return;
        
        inorder(root->left);
        // current
        if(precursor == root->val){
            cnt++;
        }else
            cnt = 1;
        
        if(cnt > mx){
            mx = cnt;
            res.clear();
            res.push_back(root->val);
        }else if(cnt == mx){
            res.push_back(root->val);
        }
        
        precursor = root->val;
        inorder(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};