class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
public:
    void dfs(int x, int y, int n, int m, vector<vector<char>>& grid){
        grid[x][y] = '0';
        
        for(int i = 0; i < 4; i++){
            int r = x + dx[i];
            int c = y + dy[i];
            
            if(r >= 0 and r < n and c >= 0 and c < m and grid[r][c] == '1')
                dfs(r, c, n, m, grid);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
       int n = grid.size();
       if(n == 0)
           return 0;
        
        int m = grid[0].size();        
        int islands = 0;
                
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(i, j, n, m, grid);
                }
            }
        }
        
        return islands;
    }
};
