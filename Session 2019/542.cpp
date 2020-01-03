class Solution {
public:
    
    struct Point{
        int x,y,dist;
    };
    
    int BFS(vector<vector<int>>& mat, int i, int j, int r, int c){
        bool visited[r][c];
        memset(visited,false,sizeof(visited));
        int row[] = {-1,1,0,0};
        int col[] = {0,0,-1,1};
        
        queue<Point> q;
        q.push({i,j,0});
        visited[i][j] = true;
        
        while(!q.empty()){
            Point pt = q.front();
            q.pop();
            
            // if found
            if(mat[pt.x][pt.y] == 0)
                return pt.dist;
            
            for(int k = 0; k < 4; k++){
                
                int a = pt.x + row[k];
                int b = pt.y + col[k];
                
                if(a>=0 and a<r and b>=0 and b<c and !visited[a][b])
                {
                    q.push({a,b,pt.dist + 1});
                    visited[a][b] = true;
                }
            }
            
        }
        
        return 0;
        
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
       int r = matrix.size();
        int c = matrix[0].size();
        
        vector<vector<int>> out(r, vector<int> (c, 0));
        
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0)
                    out[i][j] = 0;
                else 
                    out[i][j] = BFS(matrix, i, j, r, c);
            }
        
        return out;
    }
};