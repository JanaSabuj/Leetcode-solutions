class Solution {
public:
     int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool valid(int r, int c, int n, int m) {return (r >= 0 and r < n and c >= 0 and c < m);}
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        
        // find min dist to 0 -> so dist val on 0 -> so start from 1
        int ans = -1;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int r = x + dx[i];
                int c = y + dy[i];
                
                if(valid(r,c,n,m) and grid[r][c] == 0){
                    q.push({r,c});
                    dist[r][c] = dist[x][y] + abs(x - r) + abs(y - c);
                    grid[r][c] = 1;
                    
                    ans = max(ans, dist[r][c]);
                }
            }
        }
        
        return ans;
    }
};
