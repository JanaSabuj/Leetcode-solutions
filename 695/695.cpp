class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    bool valid(int r, int c, int n, int m){
        return (r >= 0 and r < n and c >= 0 and c < m);
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, int& cnt){
        grid[i][j] = 0;
        cnt++;
        
        for(int k = 0; k < 4; k++){
            int r = i + dx[k];
            int c = j + dy[k];
            
            if(valid(r, c, n, m) and grid[r][c] == 1)
                dfs(grid, r, c, n, m, cnt);
        }
        
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int sz = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int cnt = 0;
                    dfs(grid, i, j, n, m, cnt);
                    sz = max(sz, cnt);
                }
            }
        }
        
        return sz;
    }
};
