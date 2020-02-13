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

	void inorder(node* root, vector<int>& ans){
		if(root == NULL)
			return;

		inorder(root->left,ans);
		ans.push_back(root->val);
		inorder(root->right,ans);
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		inorder(root,ans);
	}
};