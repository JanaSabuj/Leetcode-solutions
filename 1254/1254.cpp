class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool valid(int r, int c, int n, int m){
        return (r >= 0 and r < n and c >= 0 and c < m);
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m){
        grid[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int r = i + dx[k];
            int c = j + dy[k];
            
            if(valid(r, c, n, m) and grid[r][c] == 0)
                dfs(grid, r, c, n, m);
        }
    }
    
    void dfs2(vector<vector<int>>& grid, int i, int j, int n, int m){
        grid[i][j] = 1;
        for(int k = 0; k < 4; k++){
            int r = i + dx[k];
            int c = j + dy[k];
            
            if(valid(r, c, n, m) and grid[r][c] == 0)
                dfs2(grid, r, c, n, m);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0 and (i == 0 || i == n-1 || j == 0 || j == m-1)){
                    dfs(grid, i, j, n, m);
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    cnt++;
                    dfs2(grid, i, j, n, m);
                }                    
            }
        }
        
        return cnt;
        
    }
};
