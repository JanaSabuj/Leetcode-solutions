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
	bool inorder(node* root) {
		stack<node*> s;
		node* prev = NULL;
		node* curr = root;

		while (1) {
			while (curr) {
				s.push(curr);
				curr = curr->left;
			}
			if (s.empty())
				break;
			curr = s.top();
			s.pop();
			if (prev != NULL and prev->val >= curr->val)
				return false;
			prev = curr;
			curr = curr->right;
		}

		return true;

	}
	bool isValidBST(TreeNode* root) {
		return inorder(root);
	}
};
