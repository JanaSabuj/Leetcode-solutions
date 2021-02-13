class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<int>& visited, int x){
        visited[x] = 1;
        for(auto v: rooms[x]){
            if(!visited[v])
                dfs(rooms, visited, v);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<int> visited(n);
        dfs(rooms, visited, 0);
        
        for(int i = 0; i < n; i++)
            if(!visited[i])
                return false;
        
        return true;
    }
};
