class Solution {
public:
    
    bool isValid(int x, int y, int n, int m){
        return (x>=0) and (x<n) and (y>=0) and (y<m);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,1,-1};
        
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        int rotten = 0, fresh = 0;//fresh
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
               if(grid[i][j] == 2){
                   rotten++;
                   q.push({i,j});
               }
                else if(grid[i][j] == 1)
                    fresh++;
            }
        
        int time = 0;
        while(!q.empty()){
            //start bfs from 2's
            bool flag = false;
            int sz = q.size();
            
            for(int i = 0; i < sz ; i++){
                pair<int,int> temp = q.front();
                q.pop();
                
                for(int j = 0; j < 4; j++){
                    int x = temp.first + dr[j];
                    int y = temp.second + dc[j];
                    
                    if(isValid(x,y,n,m))
                        if(grid[x][y] == 1){
                            //if fresh, rot it and push it into q
                            flag = true;
                            grid[x][y] = 2;
                            q.push({x,y});
                            fresh--;// 1 fresh decreased
                        }
                }
            }
            
            if(flag)
                time++;
        }
        
        if((fresh==0))
            return time;
        else
            return -1;
                
    }
};
