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
	bool isMirror(node* a, node* b){
		if(a == NULL and b == NULL)
			return true;
		if(a == NULL or b == NULL)
			return false;
		return (a->val == b->val) and isMirror(a->left, b->right) and isMirror(a->right, b->left);
	}
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isMirror(root->left, root->right);
    }
};
