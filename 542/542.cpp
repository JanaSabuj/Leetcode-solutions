class Solution {
public:
    #define inf (1 << 30)
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool valid(int r, int c, int n, int m) {return (r >= 0 and r < n and c >= 0 and c < m);}
    vector<vector<int>> bfs(vector<vector<int>>& matrix, vector<pair<int,int>>& src, int n, int m){
        vector<vector<int>> dist(n, vector<int>(m, 0));
        // find dist of all items from 0
        queue<pair<int,int>> q;        
        for(auto& [x, y]: src){
            q.push({x,y});            
            dist[x][y] = 0;
        }
        
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int r = x + dx[i];
                int c = y + dy[i];
                
                if(valid(r,c,n,m) and matrix[r][c] == 1){
                    q.push({r,c});
                    matrix[r][c] = 0;// mark as visited
                    dist[r][c] = dist[x][y] + 1;
                }
            }                        
        }
        
        return dist;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>> src;    
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    src.push_back({i,j});
                }
            }
        }
        
        
        // bfs
        vector<vector<int>> dist = bfs(matrix, src, n, m);
        return dist;
    }
};
