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
	int inorder(node* root, int k) {
		int cnt = 1;
		node* curr = root;
		stack<node*> s;

		while (1) {
			while (curr) {
				s.push(curr);
				curr = curr->left;
			}
			if (s.empty())
				break;
			curr = s.top();
			s.pop();
			if (cnt == k)
				return curr->val;
			cnt++;
			curr = curr->right;
		}
		return 0;

	}
	int kthSmallest(TreeNode* root, int k) {
		return inorder(root, k);
	}
};
