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
    
    void dfs(node* root, int tmp, int sum, vector<int> &vec){
         
        if(root == NULL)
            return;
        
        // if leaf
        if(root->left == NULL and root->right == NULL){
            if (tmp + root->val == sum)
                vec.push_back(1);
            else
                vec.push_back(-1);
        }
        
        tmp = tmp + root->val;
        dfs(root->left,tmp,sum,vec);
        dfs(root->right,tmp,sum,vec);     
              
    }
    
    
    bool hasPathSum(TreeNode* root, int sum) {
        
        int tmp=0;
        
         vector<int> vec;
         dfs(root,tmp,sum,vec);
         
        for(auto x:vec)
            if(x == 1)
                return true;
        
        return false;
        
        
    }
};