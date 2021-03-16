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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        
       node* curr = root;        
       queue<node*> q;
       q.push(root);
        
        vvi ans;
        while(!q.empty()){
            int sz = q.size();
            vi req;
            
            while(sz--){
                node* temp = q.front(); q.pop();
                req.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            
            ans.push_back(req);
        }
        
        return ans;
    }
};