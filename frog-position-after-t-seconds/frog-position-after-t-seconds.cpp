class Solution {
    double p;
public:    
    void dfs(int x, int par, vector<int> adj[], int t, int target, double prob) {
        // base
        if(p != 0.0)
            return;
        
        if(t < 0)
            return;
                                
        // final target
        if(x == target and (t == 0 || t >= 0 and ((int)adj[x].size() - (x !=1)) == 0)) {            
            p = prob;
            return;
        }
        
        // normal
        //    par
        //    x
        // u1 u2 .... un
        for(auto u: adj[x]) {
            if(u != par) {
                dfs(u, x, adj, t - 1, target, prob * 1.0 / (adj[x].size() - (x != 1)));
            }
        }
    }
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> adj[n+1];
        
        for(auto x: edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        p = 0.00;
        dfs(1, -1, adj, t, target, 1.0);
        
        return p;
    }
};