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
	void preorder(node* root, vector<int>& ans){
		stack<node*> s;
		s.push(root);

		while(!s.empty()){
			node* curr = s.top();s.pop();
			if(curr != NULL){
				s.push(curr->right);
				s.push(curr->left);
				ans.push_back(curr->val);
			}
		}

		 
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		preorder(root, ans);
        return ans;
	}
};
