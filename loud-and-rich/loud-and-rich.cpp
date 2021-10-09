class Solution {
public:
    int dfs(int x, vector<int> adj[], vector<int>& quiet, vector<int>& vis){
        vis[x] = 1;
        
        int q = quiet[x];
        for(auto v: adj[x]){
            if(!vis[v])
                q = min(q, dfs(v, adj, quiet, vis));
        }
        
        return q;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        // richer[i] = [ai, bi]  ai > bi === bi -> ai        
        // answer[x] = y [for person richer than x, person y is the quietest]
        
        int n = quiet.size();
        unordered_map<int,int> ppl;
        for(int i = 0; i < n; i++)
            ppl[quiet[i]] = i;
        vector<int> adj[n];    
        for(auto& v: richer){
            adj[v[1]].push_back(v[0]);
        }
        
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            vector<int> vis(n, 0);
            ans[i] = ppl[dfs(i, adj, quiet, vis)];
        }
        
        return ans;
    }
};