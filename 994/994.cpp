class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool valid(int r, int c, int n, int m) {return (r >= 0 and r < n and c >= 0 and c < m);}
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        int fresh = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});// rotten will start spreading
                }else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        if(fresh == 0)
            return 0;
        
        int time = -1;
        while(!q.empty()){
            int sz = q.size();
            time++;
            
            while(sz--){
                auto [x,y] = q.front();
                q.pop();
                
                for(int i = 0; i < 4; i++){
                    int r = x + dx[i];
                    int c = y + dy[i];
                    
                    if(valid(r,c,n,m) and grid[r][c] == 1){
                        // only go to a fresh apple
                        q.push({r,c});
                        grid[r][c] = 2;   
                        fresh--;
                    }
                }
            }
        }
        
        return fresh == 0 ? time: -1;
    }
};
