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
    bool flag = true;
    
    void dfs(node* root, int sum, int& cnt, int& tmp, vector<int> pars){
       if(root == NULL)
           return;
        
        vector<int> temp;
        for(auto x: pars){
            int val = x + root->val;
            if(val == sum)
                cnt++;
            temp.push_back(val);
        }
        
        // execute folln snippet if not the very first root node
        if(flag != true)
        {
            if(root->val == sum)
            cnt++;
            temp.push_back(root->val);
        }
        
        flag = false;
        
        dfs(root->left, sum, cnt, tmp, temp);
        dfs(root->right, sum, cnt, tmp, temp);
        
    }
    
    
    int pathSum(TreeNode* root, int sum) {
        
        int cnt = 0;
        int tmp = 0;
        vector<int> pars;
        pars.push_back(0);
        dfs(root, sum, cnt, tmp, pars);
         
        
        return cnt;
    }
};