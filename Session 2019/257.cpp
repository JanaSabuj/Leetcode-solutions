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

    void printPath(node* root,  vector<string> &ans, string req) {

        if (root == NULL)
            return ;

        // if leaf
        if (root->left == NULL and root->right == NULL) {

            req = req + to_string(root->val);

            ans.push_back(req);
        }

        else
        {
            req = req + to_string(root->val) + "->";
            printPath(root->left, ans, req);
            printPath(root->right, ans, req);

        }


    }

    vector<string> binaryTreePaths(TreeNode* root) {
        // vector<int> vec(10000000);
        // int len=0;
        vector<string> ans;

        string req = "";
        printPath(root, ans, req);

        return ans;
    }
};