class Solution {
public:    
    vector<vector<int>> adj;    
    string label;        
    vector<int> ans;
    
    vector<int> dfs(int x, int par){  
        
        vector<int> cnt(26, 0);
        cnt[label[x] - 'a']++;
        
        for(auto v: adj[x]){
            if(v != par){
                vector<int> f = dfs(v, x);
                for(int i = 0; i < 26; i++){
                    cnt[i] += f[i];
                }
            }
        }
                
        ans[x] = cnt[label[x]- 'a'];
        return cnt;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels){
        adj.assign(n, {});
        ans.assign(n, 0);
        label = labels;
                
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(0, -1);
        return ans;
    }
};
