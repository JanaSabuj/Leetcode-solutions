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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        queue<node*> q;
        q.push(root);
        
        vector<vector<int>> ans;
        
        int level = -1;
        while(!q.empty()){
            int sz = q.size();
            level++;
            vector<int> row(sz);
            
            for(int i = 0; i < sz; i++){
                node* t = q.front();
                q.pop();
                
                if(level & 1)
                    row[sz - 1 - i] = t->val;
                else
                    row[i] = t->val;
                
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);                    
            }
            
            ans.push_back(row);
        }
        
        return ans;
    }
};