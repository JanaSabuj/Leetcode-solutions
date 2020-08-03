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
    unordered_map<node*, node*> mp;
    void dfs(node* root, node* par){
        if(root == NULL)
            return;
        mp[root] = par;
        dfs(root->left, root);
        dfs(root->right, root);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(K == 0)
            return {target->val};
        dfs(root, NULL);
        
        queue<pair<node*, int>> q;
        unordered_map<node*, bool> visited;
        
        q.push({target, 0});
        visited[target] = true;
        
        vector<int> ans;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            
            node* x = t.first;
            int dis = t.second;
            
            if(dis == K){
                ans.push_back(x->val);                
            }
            
            
            if(x->left and !visited[x->left]){
                q.push({x->left, dis + 1});
                visited[x->left] = true;
            }
            
            if(x->right and !visited[x->right]){
                q.push({x->right, dis + 1});
                visited[x->right] = true;
            }
            
            if(mp[x] and !visited[mp[x]]){
                q.push({mp[x], dis + 1});
                visited[mp[x]] = true;
            }
        }
        
        return ans;
        
    }
};
