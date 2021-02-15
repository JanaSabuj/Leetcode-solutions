class Solution {
public:
    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    bool valid(int r, int c, int n, int m){
        return (r >= 0 and r < n and c >= 0 and c < m);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dist[n][m];
        memset(dist, -1, sizeof(dist));
        if(grid[0][0] == 1)
            return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0][0] = 0;        
                
        // start from 0 -> go to only 0s
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            
            for(int i = 0; i < 8; i++){
                int r = x + dx[i];
                int c = y + dy[i];
                
                if(valid(r,c,n,m) and grid[r][c] == 0){
                    q.push({r,c});
                    grid[r][c] = 1;
                    dist[r][c] = dist[x][y] + 1;
                }
            }
        }
        
        return dist[n-1][m-1] == -1 ? -1 : dist[n-1][m-1] + 1;
    }
};
