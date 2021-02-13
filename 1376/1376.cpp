class Solution {
public:
    vector<vector<int>> adj;
    
    int maxTime(int root, vector<int>& cost){
        // base
        
        // main
        int mx = 0;
        for(auto v: adj[root])
            mx = max(mx, maxTime(v, cost));
        return mx + cost[root];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj.assign(n + 1, {});    
        
        for(int i = 0; i < n; i++){
            int par = manager[i];
            if(par != -1)
                adj[par].push_back(i);
        }
        
        return maxTime(headID, informTime);
    }
};
