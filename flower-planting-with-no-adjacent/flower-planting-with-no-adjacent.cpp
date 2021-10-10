class Solution {
public:
    void dfs(int x, vector<int> adj[], vector<int>& color){
        vector<int> c(5, 0);
        for(auto v: adj[x]){
            if(color[v] != -1)
                c[color[v]] = 1;
        }
        
        int mycol = -1;
        for(int i = 1; i <= 4; i++){
            if(!c[i]){
                mycol = i;
                break;
            }
        }
        
        color[x] = mycol;
        
        for(auto v: adj[x]){
            if(color[v] == -1)
                dfs(v, adj, color);
        }
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> color(n+1,-1);
        vector<int> adj[n+1];
        for(auto& p: paths){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        
        for(int i = 1; i <= n; i++){
            if(color[i] == -1)
                dfs(i, adj, color);
        }
        
        vector<int> ans;
        for(int i = 1; i <= n; i++){
            ans.push_back(color[i]);
        }
        
        return ans;
    }
};