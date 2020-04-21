class Solution {
    
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1 };
    int helper(const vector<vector<int>>& grid,vector<vector<int>>& temp ,int n, int m, int x, int y){   
        
        if(x < 0 or x >= n or y < 0 or y >= m or temp[x][y] == -1 or grid[x][y] == 0)
            return 0;
            
        temp[x][y] = -1;
        
        int gg = 0;
        for(int i = 0; i < 4; i++){
            int xd = x + dx[i];
            int yd = y + dy[i];
            
            gg = max(gg, helper(grid, temp, n, m, xd, yd));
        }
        
        temp[x][y] = 1;
        
        return grid[x][y] + gg;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
       
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0){                   
                    vector<vector<int>> temp(n, vector<int>(m, 1));
                    ans = max(helper(grid,temp, n, m, i, j), ans);
                    
                }                    
            }
        }
        
        return ans;
    }
};
