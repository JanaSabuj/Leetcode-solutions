1161. Maximum Level Sum of a Binary Tree
Medium

224

13

Add to List

Share
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level X such that the sum of all the values of nodes at level X is maximal.

 

Example 1:



Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
 

Note:

The number of nodes in the given tree is between 1 and 10^4.
-10^5 <= node.val <= 10^5
Accepted
25,185
Submissions
35,354

------------------------------------------------------------------
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

	int levelOrder(node* root){
		queue<node*> q;
		q.push(root);
		q.push(NULL);

		int anssum = INT_MIN;
		int anslevel = 1;

		int l = 1;
		int sum = 0;

		while(!q.empty()){
			node* curr = q.front();
			q.pop();

			if(curr != NULL){
				// in the same level
				sum += curr->val;
				if(curr->left != NULL)
					q.push(curr->left);
				if(curr->right != NULL)
					q.push(curr->right);
			}else{
				if(sum > anssum){
					anssum = sum;
					// end of level l
					anslevel = l;
				}
				q.push(NULL);
				sum = 0;
				l++;
				if(q.front() == NULL)
					break;
			}
		}

		return anslevel;
	}

    int maxLevelSum(TreeNode* root) {
        return levelOrder(root);
    }
};