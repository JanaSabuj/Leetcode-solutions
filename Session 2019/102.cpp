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
	vector<vector<int>> bfs(node* root) {
        if(root == NULL)
            return {};
		queue<node*> q;
		q.push(root);

		vector<vector<int>> ans;
		while (!q.empty()) {
			int sz = q.size();
			vector<int> t;
			while (sz--) {
				node* curr = q.front();
				q.pop();
				t.push_back(curr->val);
				if (curr->left)
					q.push(curr->left);
				if (curr->right)
					q.push(curr->right);
			}
			ans.push_back(t);
		}
		return ans;
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		return bfs(root);
	}
};
