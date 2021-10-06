class Solution {
public:
    void dfs(int x, vector<vector<int>>& adj, vector<int>& vis){
        vis[x] = 1;
        for(auto v: adj[x]){
            if(!vis[v])
                dfs(v, adj, vis);
        }                
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        dfs(0, rooms, vis);
        
        for(int i = 0; i < n; i++){
            if(!vis[i])
                return false;
        }
        
        return true;
    }
};